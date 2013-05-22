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

/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __LINUX_SEQLOCK_H
#define __LINUX_SEQLOCK_H

#include <linux/spinlock.h>
#include <linux/preempt.h>

typedef struct {
 unsigned sequence;
 spinlock_t lock;
} seqlock_t;

#define __SEQLOCK_UNLOCKED(lockname)   { 0, __SPIN_LOCK_UNLOCKED(lockname) }

#define SEQLOCK_UNLOCKED   __SEQLOCK_UNLOCKED(old_style_seqlock_init)

#define seqlock_init(x)   do { *(x) = (seqlock_t) __SEQLOCK_UNLOCKED(x); } while (0)

#define DEFINE_SEQLOCK(x)   seqlock_t x = __SEQLOCK_UNLOCKED(x)

#define SEQCNT_ZERO { 0 }
#define seqcount_init(x) do { *(x) = (seqcount_t) SEQCNT_ZERO; } while (0)

#define write_seqlock_irqsave(lock, flags)   do { local_irq_save(flags); write_seqlock(lock); } while (0)
#define write_seqlock_irq(lock)   do { local_irq_disable(); write_seqlock(lock); } while (0)
#define write_seqlock_bh(lock)   do { local_bh_disable(); write_seqlock(lock); } while (0)
#define write_sequnlock_irqrestore(lock, flags)   do { write_sequnlock(lock); local_irq_restore(flags); } while(0)
#define write_sequnlock_irq(lock)   do { write_sequnlock(lock); local_irq_enable(); } while(0)
#define write_sequnlock_bh(lock)   do { write_sequnlock(lock); local_bh_enable(); } while(0)
#define read_seqbegin_irqsave(lock, flags)   ({ local_irq_save(flags); read_seqbegin(lock); })
#define read_seqretry_irqrestore(lock, iv, flags)   ({   int ret = read_seqretry(lock, iv);   local_irq_restore(flags);   ret;   })
#endif
