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
#ifndef __ASM_ARM_ARCH_IO_H
#define __ASM_ARM_ARCH_IO_H

#include <asm/hardware.h>

#define IO_SPACE_LIMIT 0xffffffff

#define __io(a) ((void __iomem *)(PCIO_BASE + (a)))
#define __mem_pci(a) (a)

#define PCIO_BASE 0

#ifndef __ASSEMBLER__

#define omap_readb(a) (*(volatile unsigned char *)IO_ADDRESS(a))
#define omap_readw(a) (*(volatile unsigned short *)IO_ADDRESS(a))
#define omap_readl(a) (*(volatile unsigned int *)IO_ADDRESS(a))

#define omap_writeb(v,a) (*(volatile unsigned char *)IO_ADDRESS(a) = (v))
#define omap_writew(v,a) (*(volatile unsigned short *)IO_ADDRESS(a) = (v))
#define omap_writel(v,a) (*(volatile unsigned int *)IO_ADDRESS(a) = (v))

typedef struct { volatile u16 offset[256]; } __regbase16;
#define __REGV16(vaddr) ((__regbase16 *)((vaddr)&~0xff))   ->offset[((vaddr)&0xff)>>1]
#define __REG16(paddr) __REGV16(io_p2v(paddr))

typedef struct { volatile u8 offset[4096]; } __regbase8;
#define __REGV8(vaddr) ((__regbase8 *)((vaddr)&~4095))   ->offset[((vaddr)&4095)>>0]
#define __REG8(paddr) __REGV8(io_p2v(paddr))

typedef struct { volatile u32 offset[4096]; } __regbase32;
#define __REGV32(vaddr) ((__regbase32 *)((vaddr)&~4095))   ->offset[((vaddr)&4095)>>2]
#define __REG32(paddr) __REGV32(io_p2v(paddr))

#else

#define __REG8(paddr) io_p2v(paddr)
#define __REG16(paddr) io_p2v(paddr)
#define __REG32(paddr) io_p2v(paddr)

#endif

#endif
