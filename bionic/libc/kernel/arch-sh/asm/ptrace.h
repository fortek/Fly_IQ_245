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
#ifndef __ASM_SH_PTRACE_H
#define __ASM_SH_PTRACE_H

#ifdef __SH5__
struct pt_regs {
 unsigned long long pc;
 unsigned long long sr;
 unsigned long long syscall_nr;
 unsigned long long regs[63];
 unsigned long long tregs[8];
 unsigned long long pad[2];
};
#else

#define REG_REG0 0
#define REG_REG15 15

#define REG_PC 16

#define REG_PR 17
#define REG_SR 18
#define REG_GBR 19
#define REG_MACH 20
#define REG_MACL 21

#define REG_SYSCALL 22

#define REG_FPREG0 23
#define REG_FPREG15 38
#define REG_XFREG0 39
#define REG_XFREG15 54

#define REG_FPSCR 55
#define REG_FPUL 56

struct pt_regs {
 unsigned long regs[16];
 unsigned long pc;
 unsigned long pr;
 unsigned long sr;
 unsigned long gbr;
 unsigned long mach;
 unsigned long macl;
 long tra;
};

struct pt_dspregs {
 unsigned long a1;
 unsigned long a0g;
 unsigned long a1g;
 unsigned long m0;
 unsigned long m1;
 unsigned long a0;
 unsigned long x0;
 unsigned long x1;
 unsigned long y0;
 unsigned long y1;
 unsigned long dsr;
 unsigned long rs;
 unsigned long re;
 unsigned long mod;
};

#define PTRACE_GETFDPIC 31  

#define PTRACE_GETFDPIC_EXEC 0  
#define PTRACE_GETFDPIC_INTERP 1  

#define PTRACE_GETDSPREGS 55
#define PTRACE_SETDSPREGS 56
#endif

#endif
