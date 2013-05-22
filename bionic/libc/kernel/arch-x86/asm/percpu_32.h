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
#ifndef __ARCH_I386_PERCPU__
#define __ARCH_I386_PERCPU__

#ifdef __ASSEMBLY__

#define PER_CPU(var, reg)   movl $per_cpu__##var, reg
#define PER_CPU_VAR(var) per_cpu__##var

#else

#include <asm-generic/percpu.h>
#define __percpu_seg ""

#define percpu_to_op(op,var,val)   do {   typedef typeof(var) T__;   if (0) { T__ tmp__; tmp__ = (val); }   switch (sizeof(var)) {   case 1:   asm(op "b %1,"__percpu_seg"%0"   : "+m" (var)   :"ri" ((T__)val));   break;   case 2:   asm(op "w %1,"__percpu_seg"%0"   : "+m" (var)   :"ri" ((T__)val));   break;   case 4:   asm(op "l %1,"__percpu_seg"%0"   : "+m" (var)   :"ri" ((T__)val));   break;   default: __bad_percpu_size();   }   } while (0)

#define percpu_from_op(op,var)   ({   typeof(var) ret__;   switch (sizeof(var)) {   case 1:   asm(op "b "__percpu_seg"%1,%0"   : "=r" (ret__)   : "m" (var));   break;   case 2:   asm(op "w "__percpu_seg"%1,%0"   : "=r" (ret__)   : "m" (var));   break;   case 4:   asm(op "l "__percpu_seg"%1,%0"   : "=r" (ret__)   : "m" (var));   break;   default: __bad_percpu_size();   }   ret__; })

#define x86_read_percpu(var) percpu_from_op("mov", per_cpu__##var)
#define x86_write_percpu(var,val) percpu_to_op("mov", per_cpu__##var, val)
#define x86_add_percpu(var,val) percpu_to_op("add", per_cpu__##var, val)
#define x86_sub_percpu(var,val) percpu_to_op("sub", per_cpu__##var, val)
#define x86_or_percpu(var,val) percpu_to_op("or", per_cpu__##var, val)
#endif

#endif
