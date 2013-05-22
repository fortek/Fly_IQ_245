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
#ifndef _I386_TLBFLUSH_H
#define _I386_TLBFLUSH_H

#include <linux/mm.h>
#include <asm/processor.h>

#define __flush_tlb() __native_flush_tlb()
#define __flush_tlb_global() __native_flush_tlb_global()
#define __flush_tlb_single(addr) __native_flush_tlb_single(addr)

#define __native_flush_tlb()   do {   unsigned int tmpreg;     __asm__ __volatile__(   "movl %%cr3, %0;              \n"   "movl %0, %%cr3;  # flush TLB \n"   : "=r" (tmpreg)   :: "memory");   } while (0)

#define __native_flush_tlb_global()   do {   unsigned int tmpreg, cr4, cr4_orig;     __asm__ __volatile__(   "movl %%cr4, %2;  # turn off PGE     \n"   "movl %2, %1;                        \n"   "andl %3, %1;                        \n"   "movl %1, %%cr4;                     \n"   "movl %%cr3, %0;                     \n"   "movl %0, %%cr3;  # flush TLB        \n"   "movl %2, %%cr4;  # turn PGE back on \n"   : "=&r" (tmpreg), "=&r" (cr4), "=&r" (cr4_orig)   : "i" (~X86_CR4_PGE)   : "memory");   } while (0)

#define __native_flush_tlb_single(addr)   __asm__ __volatile__("invlpg (%0)" ::"r" (addr) : "memory")

#define __flush_tlb_all()   do {   if (cpu_has_pge)   __flush_tlb_global();   else   __flush_tlb();   } while (0)

#define cpu_has_invlpg (boot_cpu_data.x86 > 3)

#define __flush_tlb_one(addr)   do {   if (cpu_has_invlpg)   __flush_tlb_single(addr);   else   __flush_tlb();   } while (0)

#define TLB_FLUSH_ALL 0xffffffff

#include <linux/sched.h>

#define flush_tlb() __flush_tlb()
#define flush_tlb_all() __flush_tlb_all()
#define local_flush_tlb() __flush_tlb()

#define flush_tlb_others(mask, mm, va)   native_flush_tlb_others(&mask, mm, va)
#endif
