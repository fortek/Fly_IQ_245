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
#ifndef _SERIO_H
#define _SERIO_H

#include <linux/ioctl.h>

#define SPIOCSTYPE _IOW('q', 0x01, unsigned long)

#define SERIO_TIMEOUT 1
#define SERIO_PARITY 2
#define SERIO_FRAME 4

#define SERIO_XT 0x00
#define SERIO_8042 0x01
#define SERIO_RS232 0x02
#define SERIO_HIL_MLC 0x03
#define SERIO_PS_PSTHRU 0x05
#define SERIO_8042_XL 0x06

#define SERIO_UNKNOWN 0x00
#define SERIO_MSC 0x01
#define SERIO_SUN 0x02
#define SERIO_MS 0x03
#define SERIO_MP 0x04
#define SERIO_MZ 0x05
#define SERIO_MZP 0x06
#define SERIO_MZPP 0x07
#define SERIO_VSXXXAA 0x08
#define SERIO_SUNKBD 0x10
#define SERIO_WARRIOR 0x18
#define SERIO_SPACEORB 0x19
#define SERIO_MAGELLAN 0x1a
#define SERIO_SPACEBALL 0x1b
#define SERIO_GUNZE 0x1c
#define SERIO_IFORCE 0x1d
#define SERIO_STINGER 0x1e
#define SERIO_NEWTON 0x1f
#define SERIO_STOWAWAY 0x20
#define SERIO_H3600 0x21
#define SERIO_PS2SER 0x22
#define SERIO_TWIDKBD 0x23
#define SERIO_TWIDJOY 0x24
#define SERIO_HIL 0x25
#define SERIO_SNES232 0x26
#define SERIO_SEMTECH 0x27
#define SERIO_LKKBD 0x28
#define SERIO_ELO 0x29
#define SERIO_MICROTOUCH 0x30

#endif