/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "linker.h"
#include "linker_debug.h"
#include "ba.h"

#undef min
#define min(a,b) ((a)<(b)?(a):(b))

#define BA_IS_FREE(index) (!(ba->bitmap[index].allocated))
#define BA_ORDER(index) ba->bitmap[index].order
#define BA_BUDDY_INDEX(index) ((index) ^ (1 << BA_ORDER(index)))
#define BA_NEXT_INDEX(index) ((index) + (1 << BA_ORDER(index)))
#define BA_OFFSET(index) ((index) * ba->min_alloc)
#define BA_START_ADDR(index) (BA_OFFSET(index) + ba->base)
#define BA_LEN(index) ((1 << BA_ORDER(index)) * ba->min_alloc)

static unsigned long ba_order(struct ba *ba, unsigned long len);

void ba_init(struct ba *ba)
{
    int i, index = 0;

    unsigned long max_order = ba_order(ba, ba->size);
    if (ba->max_order == 0 || ba->max_order > max_order)
        ba->max_order = max_order;

    for (i = sizeof(ba->num_entries) * 8 - 1; i >= 0; i--) {
        if (ba->num_entries &  1<<i) {
            BA_ORDER(index) = i;
            index = BA_NEXT_INDEX(index);
        }
    }
}

int ba_free(struct ba *ba, int index)
{
    int buddy, curr = index;

    /* clean up the bitmap, merging any buddies */
    ba->bitmap[curr].allocated = 0;
    /* find a slots buddy Buddy# = Slot# ^ (1 << order)
     * if the buddy is also free merge them
     * repeat until the buddy is not free or end of the bitmap is reached
     */
    do {
        buddy = BA_BUDDY_INDEX(curr);
        if (BA_IS_FREE(buddy) &&
                BA_ORDER(buddy) == BA_ORDER(curr)) {
            BA_ORDER(buddy)++;
            BA_ORDER(curr)++;
            curr = min(buddy, curr);
        } else {
            break;
        }
    } while (curr < ba->num_entries);

    return 0;
}

static unsigned long ba_order(struct ba *ba, unsigned long len)
{
    unsigned long i;

    len = (len + ba->min_alloc - 1) / ba->min_alloc;
    len--;
    for (i = 0; i < sizeof(len)*8; i++)
        if (len >> i == 0)
            break;
    return i;
}

int ba_allocate(struct ba *ba, unsigned long len)
{
    int curr = 0;
    int end = ba->num_entries;
    int best_fit = -1;
    unsigned long order = ba_order(ba, len);

    if (order > ba->max_order)
        return -1;

    /* look through the bitmap:
     *  if you find a free slot of the correct order use it
     *  otherwise, use the best fit (smallest with size > order) slot
     */
    while (curr < end) {
        if (BA_IS_FREE(curr)) {
            if (BA_ORDER(curr) == (unsigned char)order) {
                /* set the not free bit and clear others */
                best_fit = curr;
                break;
            }
            if (BA_ORDER(curr) > (unsigned char)order &&
                (best_fit < 0 ||
                 BA_ORDER(curr) < BA_ORDER(best_fit)))
                best_fit = curr;
        }
        curr = BA_NEXT_INDEX(curr);
    }

    /* if best_fit < 0, there are no suitable slots,
     * return an error
     */
    if (best_fit < 0)
        return -1;

    /* now partition the best fit:
     *  split the slot into 2 buddies of order - 1
     *  repeat until the slot is of the correct order
     */
    while (BA_ORDER(best_fit) > (unsigned char)order) {
        int buddy;
        BA_ORDER(best_fit) -= 1;
        buddy = BA_BUDDY_INDEX(best_fit);
        BA_ORDER(buddy) = BA_ORDER(best_fit);
    }
    ba->bitmap[best_fit].allocated = 1;
    return best_fit;
}

unsigned long ba_start_addr(struct ba *ba, int index)
{
    return BA_START_ADDR(index);
}

unsigned long ba_len(struct ba *ba, int index)
{
    return BA_LEN(index);
}
