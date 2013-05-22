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
#ifndef __LINUX_SPINLOCK_H
#define __LINUX_SPINLOCK_H

#include <linux/preempt.h>
#include <linux/linkage.h>
#include <linux/compiler.h>
#include <linux/thread_info.h>
#include <linux/kernel.h>
#include <linux/stringify.h>

#include <asm/system.h>

#define LOCK_SECTION_NAME ".text.lock."KBUILD_BASENAME

#define LOCK_SECTION_START(extra)   ".subsection 1\n\t"   extra   ".ifndef " LOCK_SECTION_NAME "\n\t"   LOCK_SECTION_NAME ":\n\t"   ".endif\n"

#define LOCK_SECTION_END   ".previous\n\t"

#define __lockfunc fastcall __attribute__((section(".spinlock.text")))

#include <linux/spinlock_types.h>

#include <linux/spinlock_up.h>

#define spin_lock_init(lock)   do { *(lock) = SPIN_LOCK_UNLOCKED; } while (0)

#define rwlock_init(lock)   do { *(lock) = RW_LOCK_UNLOCKED; } while (0)

#define spin_is_locked(lock) __raw_spin_is_locked(&(lock)->raw_lock)

#define spin_unlock_wait(lock) __raw_spin_unlock_wait(&(lock)->raw_lock)

#include <linux/spinlock_api_up.h>

#define _raw_spin_lock(lock) __raw_spin_lock(&(lock)->raw_lock)
#define _raw_spin_lock_flags(lock, flags)   __raw_spin_lock_flags(&(lock)->raw_lock, *(flags))
#define _raw_spin_trylock(lock) __raw_spin_trylock(&(lock)->raw_lock)
#define _raw_spin_unlock(lock) __raw_spin_unlock(&(lock)->raw_lock)
#define _raw_read_lock(rwlock) __raw_read_lock(&(rwlock)->raw_lock)
#define _raw_read_trylock(rwlock) __raw_read_trylock(&(rwlock)->raw_lock)
#define _raw_read_unlock(rwlock) __raw_read_unlock(&(rwlock)->raw_lock)
#define _raw_write_lock(rwlock) __raw_write_lock(&(rwlock)->raw_lock)
#define _raw_write_trylock(rwlock) __raw_write_trylock(&(rwlock)->raw_lock)
#define _raw_write_unlock(rwlock) __raw_write_unlock(&(rwlock)->raw_lock)

#define read_can_lock(rwlock) __raw_read_can_lock(&(rwlock)->raw_lock)
#define write_can_lock(rwlock) __raw_write_can_lock(&(rwlock)->raw_lock)

#define spin_trylock(lock) __cond_lock(_spin_trylock(lock))
#define read_trylock(lock) __cond_lock(_read_trylock(lock))
#define write_trylock(lock) __cond_lock(_write_trylock(lock))

#define spin_lock(lock) _spin_lock(lock)

#define spin_lock_nested(lock, subclass) _spin_lock(lock)

#define write_lock(lock) _write_lock(lock)
#define read_lock(lock) _read_lock(lock)

#define spin_lock_irqsave(lock, flags) _spin_lock_irqsave(lock, flags)
#define read_lock_irqsave(lock, flags) _read_lock_irqsave(lock, flags)
#define write_lock_irqsave(lock, flags) _write_lock_irqsave(lock, flags)

#define spin_lock_irq(lock) _spin_lock_irq(lock)
#define spin_lock_bh(lock) _spin_lock_bh(lock)

#define read_lock_irq(lock) _read_lock_irq(lock)
#define read_lock_bh(lock) _read_lock_bh(lock)

#define write_lock_irq(lock) _write_lock_irq(lock)
#define write_lock_bh(lock) _write_lock_bh(lock)

#define spin_unlock(lock) _spin_unlock(lock)
#define read_unlock(lock) _read_unlock(lock)
#define write_unlock(lock) _write_unlock(lock)
#define spin_unlock_irq(lock) _spin_unlock_irq(lock)
#define read_unlock_irq(lock) _read_unlock_irq(lock)
#define write_unlock_irq(lock) _write_unlock_irq(lock)

#define spin_unlock_irqrestore(lock, flags)   _spin_unlock_irqrestore(lock, flags)
#define spin_unlock_bh(lock) _spin_unlock_bh(lock)

#define read_unlock_irqrestore(lock, flags)   _read_unlock_irqrestore(lock, flags)
#define read_unlock_bh(lock) _read_unlock_bh(lock)

#define write_unlock_irqrestore(lock, flags)   _write_unlock_irqrestore(lock, flags)
#define write_unlock_bh(lock) _write_unlock_bh(lock)

#define spin_trylock_bh(lock) __cond_lock(_spin_trylock_bh(lock))

#define spin_trylock_irq(lock)  ({   local_irq_disable();   _spin_trylock(lock) ?   1 : ({ local_irq_enable(); 0; });  })

#define spin_trylock_irqsave(lock, flags)  ({   local_irq_save(flags);   _spin_trylock(lock) ?   1 : ({ local_irq_restore(flags); 0; });  })

#include <asm/atomic.h>

#define atomic_dec_and_lock(atomic, lock)   __cond_lock(_atomic_dec_and_lock(atomic, lock))

#define spin_can_lock(lock) (!spin_is_locked(lock))

#endif
