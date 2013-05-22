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
#ifndef __HYPERCALL_H__
#define __HYPERCALL_H__

#include <linux/errno.h>
#include <linux/string.h>

#include <xen/interface/xen.h>
#include <xen/interface/sched.h>
#include <xen/interface/physdev.h>

#define _hypercall0(type, name)  ({   long __res;   asm volatile (   "call %[call]"   : "=a" (__res)   : [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#define _hypercall1(type, name, a1)  ({   long __res, __ign1;   asm volatile (   "call %[call]"   : "=a" (__res), "=b" (__ign1)   : "1" ((long)(a1)),   [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#define _hypercall2(type, name, a1, a2)  ({   long __res, __ign1, __ign2;   asm volatile (   "call %[call]"   : "=a" (__res), "=b" (__ign1), "=c" (__ign2)   : "1" ((long)(a1)), "2" ((long)(a2)),   [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#define _hypercall3(type, name, a1, a2, a3)  ({   long __res, __ign1, __ign2, __ign3;   asm volatile (   "call %[call]"   : "=a" (__res), "=b" (__ign1), "=c" (__ign2),   "=d" (__ign3)   : "1" ((long)(a1)), "2" ((long)(a2)),   "3" ((long)(a3)),   [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#define _hypercall4(type, name, a1, a2, a3, a4)  ({   long __res, __ign1, __ign2, __ign3, __ign4;   asm volatile (   "call %[call]"   : "=a" (__res), "=b" (__ign1), "=c" (__ign2),   "=d" (__ign3), "=S" (__ign4)   : "1" ((long)(a1)), "2" ((long)(a2)),   "3" ((long)(a3)), "4" ((long)(a4)),   [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#define _hypercall5(type, name, a1, a2, a3, a4, a5)  ({   long __res, __ign1, __ign2, __ign3, __ign4, __ign5;   asm volatile (   "call %[call]"   : "=a" (__res), "=b" (__ign1), "=c" (__ign2),   "=d" (__ign3), "=S" (__ign4), "=D" (__ign5)   : "1" ((long)(a1)), "2" ((long)(a2)),   "3" ((long)(a3)), "4" ((long)(a4)),   "5" ((long)(a5)),   [call] "m" (hypercall_page[__HYPERVISOR_##name])   : "memory" );   (type)__res;  })

#endif
