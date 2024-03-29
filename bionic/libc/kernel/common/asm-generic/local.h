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
#ifndef _ASM_GENERIC_LOCAL_H
#define _ASM_GENERIC_LOCAL_H

#include <linux/percpu.h>
#include <linux/hardirq.h>
#include <asm/atomic.h>
#include <asm/types.h>

typedef struct
{
 atomic_long_t a;
} local_t;

#define LOCAL_INIT(i) { ATOMIC_LONG_INIT(i) }

#define local_read(l) atomic_long_read(&(l)->a)
#define local_set(l,i) atomic_long_set((&(l)->a),(i))
#define local_inc(l) atomic_long_inc(&(l)->a)
#define local_dec(l) atomic_long_dec(&(l)->a)
#define local_add(i,l) atomic_long_add((i),(&(l)->a))
#define local_sub(i,l) atomic_long_sub((i),(&(l)->a))

#define __local_inc(l) local_set((l), local_read(l) + 1)
#define __local_dec(l) local_set((l), local_read(l) - 1)
#define __local_add(i,l) local_set((l), local_read(l) + (i))
#define __local_sub(i,l) local_set((l), local_read(l) - (i))

#define cpu_local_read(v) local_read(&__get_cpu_var(v))
#define cpu_local_set(v, i) local_set(&__get_cpu_var(v), (i))
#define cpu_local_inc(v) local_inc(&__get_cpu_var(v))
#define cpu_local_dec(v) local_dec(&__get_cpu_var(v))
#define cpu_local_add(i, v) local_add((i), &__get_cpu_var(v))
#define cpu_local_sub(i, v) local_sub((i), &__get_cpu_var(v))

#define __cpu_local_inc(v) __local_inc(&__get_cpu_var(v))
#define __cpu_local_dec(v) __local_dec(&__get_cpu_var(v))
#define __cpu_local_add(i, v) __local_add((i), &__get_cpu_var(v))
#define __cpu_local_sub(i, v) __local_sub((i), &__get_cpu_var(v))

#endif
