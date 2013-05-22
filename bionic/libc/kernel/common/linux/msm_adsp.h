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
#ifndef __LINUX_MSM_ADSP_H
#define __LINUX_MSM_ADSP_H

#include <linux/types.h>
#include <linux/ioctl.h>

#define ADSP_IOCTL_MAGIC 'q'

struct adsp_command_t {
 uint16_t queue;
 uint32_t len;
 uint8_t *data;
};

struct adsp_event_t {
 uint16_t type;
 uint32_t timeout_ms;
 uint16_t msg_id;
 uint16_t flags;
 uint32_t len;
 uint8_t *data;
};

#define ADSP_IOCTL_ENABLE _IOR(ADSP_IOCTL_MAGIC, 1, unsigned)

#define ADSP_IOCTL_DISABLE _IOR(ADSP_IOCTL_MAGIC, 2, unsigned)

#define ADSP_IOCTL_DISABLE_ACK _IOR(ADSP_IOCTL_MAGIC, 3, unsigned)

#define ADSP_IOCTL_WRITE_COMMAND _IOR(ADSP_IOCTL_MAGIC, 4, struct adsp_command_t *)

#define ADSP_IOCTL_GET_EVENT _IOWR(ADSP_IOCTL_MAGIC, 5, struct adsp_event_data_t *)

#define ADSP_IOCTL_SET_CLKRATE _IOR(ADSP_IOCTL_MAGIC, 6, unsigned)

#define ADSP_IOCTL_DISABLE_EVENT_RSP _IOR(ADSP_IOCTL_MAGIC, 10, unsigned)

struct adsp_pmem_info {
 int fd;
 void *vaddr;
};

#define ADSP_IOCTL_REGISTER_PMEM _IOW(ADSP_IOCTL_MAGIC, 13, unsigned)

#define ADSP_IOCTL_UNREGISTER_PMEM _IOW(ADSP_IOCTL_MAGIC, 14, unsigned)

#define ADSP_IOCTL_ABORT_EVENT_READ _IOW(ADSP_IOCTL_MAGIC, 15, unsigned)

#define ADSP_IOCTL_LINK_TASK _IOW(ADSP_IOCTL_MAGIC, 16, unsigned)

#endif

