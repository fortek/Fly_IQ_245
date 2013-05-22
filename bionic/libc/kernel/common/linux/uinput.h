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
#ifndef __UINPUT_H_
#define __UINPUT_H_

#include <linux/input.h>

#define UINPUT_VERSION 3

struct uinput_ff_upload {
 int request_id;
 int retval;
 struct ff_effect effect;
 struct ff_effect old;
};

struct uinput_ff_erase {
 int request_id;
 int retval;
 int effect_id;
};

#define UINPUT_IOCTL_BASE 'U'
#define UI_DEV_CREATE _IO(UINPUT_IOCTL_BASE, 1)
#define UI_DEV_DESTROY _IO(UINPUT_IOCTL_BASE, 2)

#define UI_SET_EVBIT _IOW(UINPUT_IOCTL_BASE, 100, int)
#define UI_SET_KEYBIT _IOW(UINPUT_IOCTL_BASE, 101, int)
#define UI_SET_RELBIT _IOW(UINPUT_IOCTL_BASE, 102, int)
#define UI_SET_ABSBIT _IOW(UINPUT_IOCTL_BASE, 103, int)
#define UI_SET_MSCBIT _IOW(UINPUT_IOCTL_BASE, 104, int)
#define UI_SET_LEDBIT _IOW(UINPUT_IOCTL_BASE, 105, int)
#define UI_SET_SNDBIT _IOW(UINPUT_IOCTL_BASE, 106, int)
#define UI_SET_FFBIT _IOW(UINPUT_IOCTL_BASE, 107, int)
#define UI_SET_PHYS _IOW(UINPUT_IOCTL_BASE, 108, char*)
#define UI_SET_SWBIT _IOW(UINPUT_IOCTL_BASE, 109, int)

#define UI_BEGIN_FF_UPLOAD _IOWR(UINPUT_IOCTL_BASE, 200, struct uinput_ff_upload)
#define UI_END_FF_UPLOAD _IOW(UINPUT_IOCTL_BASE, 201, struct uinput_ff_upload)
#define UI_BEGIN_FF_ERASE _IOWR(UINPUT_IOCTL_BASE, 202, struct uinput_ff_erase)
#define UI_END_FF_ERASE _IOW(UINPUT_IOCTL_BASE, 203, struct uinput_ff_erase)

#define EV_UINPUT 0x0101
#define UI_FF_UPLOAD 1
#define UI_FF_ERASE 2

#define UINPUT_MAX_NAME_SIZE 80
struct uinput_user_dev {
 char name[UINPUT_MAX_NAME_SIZE];
 struct input_id id;
 int ff_effects_max;
 int absmax[ABS_MAX + 1];
 int absmin[ABS_MAX + 1];
 int absfuzz[ABS_MAX + 1];
 int absflat[ABS_MAX + 1];
};
#endif

