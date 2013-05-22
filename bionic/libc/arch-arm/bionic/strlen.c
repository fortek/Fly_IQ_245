/* Copyright Statement:
 * 
 * This software/firmware and related documentation ("MediaTek Software") are 
 * protected under relevant copyright laws. The information contained herein is 
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without 
 * the prior written permission of MediaTek inc. and/or its licensors, any 
 * reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly 
 * prohibited.  
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") 
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON 
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER 
 * DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF 
 * ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE 
 * MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR 
 * ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT 
 * IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER 
 * LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE 
 * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S 
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. 
 * RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE 
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, 
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
#include <string.h>
#include <stdint.h>
#include <machine/cpu-features.h>

size_t strlen(const char *s)
{
    __builtin_prefetch(s);
    __builtin_prefetch(s+32);
    
    union {
        const char      *b;
        const uint32_t  *w;
        uintptr_t       i;
    } u;
    
    // these are some scratch variables for the asm code below
    uint32_t v, t;
    
    // initialize the string length to zero
    size_t l = 0;

    // align the pointer to a 32-bit word boundary
    u.b = s;
    while (u.i & 0x3)  {
        if (__builtin_expect(*u.b++ == 0, 0)) {
            goto done;
        }
        l++;
    }

    // loop for each word, testing if it contains a zero byte
    // if so, exit the loop and update the length.
    // We need to process 32 bytes per loop to schedule PLD properly
    // and achieve the maximum bus speed.
    asm(
        "ldr     %[v], [ %[s] ], #4         \n"
        "sub     %[l], %[l], %[s]           \n"
        "0:                                 \n"
#if __ARM_HAVE_PLD
        "pld     [ %[s], #64 ]              \n"
#endif
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
#if !defined(__OPTIMIZE_SIZE__)
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
        "bne     1f                         \n"
        "sub     %[t], %[v], %[mask], lsr #7\n"
        "and     %[t], %[t], %[mask]        \n"
        "bics    %[t], %[t], %[v]           \n"
        "ldreq   %[v], [ %[s] ], #4         \n"
#endif
        "beq     0b                         \n"
        "1:                                 \n"
        "add     %[l], %[l], %[s]           \n"
        "tst     %[v], #0xFF                \n"
        "beq     2f                         \n"
        "add     %[l], %[l], #1             \n"
        "tst     %[v], #0xFF00              \n"
        "beq     2f                         \n"
        "add     %[l], %[l], #1             \n"
        "tst     %[v], #0xFF0000            \n"
        "addne   %[l], %[l], #1             \n"
        "2:                                 \n"
        : [l]"=&r"(l), [v]"=&r"(v), [t]"=&r"(t), [s]"=&r"(u.b)
        : "%[l]"(l), "%[s]"(u.b), [mask]"r"(0x80808080UL)
        : "cc"
    );
    
done:
    return l;
}
