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
#ifndef __LINUX_CAPI_H__
#define __LINUX_CAPI_H__

#include <asm/types.h>
#include <linux/ioctl.h>
#include <linux/kernelcapi.h>

typedef struct capi_register_params {
 __u32 level3cnt;
 __u32 datablkcnt;
 __u32 datablklen;
} capi_register_params;

#define CAPI_REGISTER _IOW('C',0x01,struct capi_register_params)

#define CAPI_MANUFACTURER_LEN 64

#define CAPI_GET_MANUFACTURER _IOWR('C',0x06,int)  

typedef struct capi_version {
 __u32 majorversion;
 __u32 minorversion;
 __u32 majormanuversion;
 __u32 minormanuversion;
} capi_version;

#define CAPI_GET_VERSION _IOWR('C',0x07,struct capi_version)

#define CAPI_SERIAL_LEN 8
#define CAPI_GET_SERIAL _IOWR('C',0x08,int)  

typedef struct capi_profile {
 __u16 ncontroller;
 __u16 nbchannel;
 __u32 goptions;
 __u32 support1;
 __u32 support2;
 __u32 support3;
 __u32 reserved[6];
 __u32 manu[5];
} capi_profile;

#define CAPI_GET_PROFILE _IOWR('C',0x09,struct capi_profile)

typedef struct capi_manufacturer_cmd {
 unsigned long cmd;
 void __user *data;
} capi_manufacturer_cmd;

#define CAPI_MANUFACTURER_CMD _IOWR('C',0x20, struct capi_manufacturer_cmd)

#define CAPI_GET_ERRCODE _IOR('C',0x21, __u16)

#define CAPI_INSTALLED _IOR('C',0x22, __u16)

typedef union capi_ioctl_struct {
 __u32 contr;
 capi_register_params rparams;
 __u8 manufacturer[CAPI_MANUFACTURER_LEN];
 capi_version version;
 __u8 serial[CAPI_SERIAL_LEN];
 capi_profile profile;
 capi_manufacturer_cmd cmd;
 __u16 errcode;
} capi_ioctl_struct;

#define CAPIFLAG_HIGHJACKING 0x0001

#define CAPI_GET_FLAGS _IOR('C',0x23, unsigned)
#define CAPI_SET_FLAGS _IOR('C',0x24, unsigned)
#define CAPI_CLR_FLAGS _IOR('C',0x25, unsigned)

#define CAPI_NCCI_OPENCOUNT _IOR('C',0x26, unsigned)

#define CAPI_NCCI_GETUNIT _IOR('C',0x27, unsigned)

#endif
