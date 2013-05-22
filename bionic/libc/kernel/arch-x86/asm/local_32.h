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
#ifndef _ARCH_I386_LOCAL_H
#define _ARCH_I386_LOCAL_H

#include <linux/percpu.h>
#include <asm/system.h>
#include <asm/atomic.h>

typedef struct
{
 atomic_long_t a;
} local_t;

#define LOCAL_INIT(i) { ATOMIC_LONG_INIT(i) }

#define local_read(l) atomic_long_read(&(l)->a)
#define local_set(l,i) atomic_long_set(&(l)->a, (i))

#define local_inc_return(l) (local_add_return(1,l))
#define local_dec_return(l) (local_sub_return(1,l))
#define local_cmpxchg(l, o, n)   (cmpxchg_local(&((l)->a.counter), (o), (n)))
#define local_xchg(l, n) (xchg(&((l)->a.counter), (n)))
#define local_add_unless(l, a, u)  ({   long c, old;   c = local_read(l);   for (;;) {   if (unlikely(c == (u)))   break;   old = local_cmpxchg((l), c, c + (a));   if (likely(old == c))   break;   c = old;   }   c != (u);  })
#define local_inc_not_zero(l) local_add_unless((l), 1, 0)
#define __local_inc(l) local_inc(l)
#define __local_dec(l) local_dec(l)
#define __local_add(i,l) local_add((i),(l))
#define __local_sub(i,l) local_sub((i),(l))
#define cpu_local_wrap_v(l)   ({ local_t res__;   preempt_disable();   res__ = (l);   preempt_enable();   res__; })
#define cpu_local_wrap(l)   ({ preempt_disable();   l;   preempt_enable(); })  
#define cpu_local_read(l) cpu_local_wrap_v(local_read(&__get_cpu_var(l)))
#define cpu_local_set(l, i) cpu_local_wrap(local_set(&__get_cpu_var(l), (i)))
#define cpu_local_inc(l) cpu_local_wrap(local_inc(&__get_cpu_var(l)))
#define cpu_local_dec(l) cpu_local_wrap(local_dec(&__get_cpu_var(l)))
#define cpu_local_add(i, l) cpu_local_wrap(local_add((i), &__get_cpu_var(l)))
#define cpu_local_sub(i, l) cpu_local_wrap(local_sub((i), &__get_cpu_var(l)))
#define __cpu_local_inc(l) cpu_local_inc(l)
#define __cpu_local_dec(l) cpu_local_dec(l)
#define __cpu_local_add(i, l) cpu_local_add((i), (l))
#define __cpu_local_sub(i, l) cpu_local_sub((i), (l))
#endif
