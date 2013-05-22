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
#ifndef __ASM_ARCH_OMAP_GPIO_H
#define __ASM_ARCH_OMAP_GPIO_H

#include <asm/hardware.h>
#include <asm/arch/irqs.h>
#include <asm/io.h>

#define OMAP_MPUIO_BASE (void __iomem *)0xfffb5000

#define OMAP_MPUIO_INPUT_LATCH 0x00
#define OMAP_MPUIO_OUTPUT 0x04
#define OMAP_MPUIO_IO_CNTL 0x08
#define OMAP_MPUIO_KBR_LATCH 0x10
#define OMAP_MPUIO_KBC 0x14
#define OMAP_MPUIO_GPIO_EVENT_MODE 0x18
#define OMAP_MPUIO_GPIO_INT_EDGE 0x1c
#define OMAP_MPUIO_KBD_INT 0x20
#define OMAP_MPUIO_GPIO_INT 0x24
#define OMAP_MPUIO_KBD_MASKIT 0x28
#define OMAP_MPUIO_GPIO_MASKIT 0x2c
#define OMAP_MPUIO_GPIO_DEBOUNCING 0x30
#define OMAP_MPUIO_LATCH 0x34

#define OMAP_MPUIO(nr) (OMAP_MAX_GPIO_LINES + (nr))
#define OMAP_GPIO_IS_MPUIO(nr) ((nr) >= OMAP_MAX_GPIO_LINES)

#define OMAP_GPIO_IRQ(nr) (OMAP_GPIO_IS_MPUIO(nr) ?   IH_MPUIO_BASE + ((nr) & 0x0f) :   IH_GPIO_BASE + (nr))

struct omap_machine_gpio_bank {
 int start;
 int end;

 void (*set_gpio_direction)(int gpio, int is_input);
 void (*set_gpio_dataout)(int gpio, int enable);
 int (*get_gpio_datain)(int gpio);
};

#endif
