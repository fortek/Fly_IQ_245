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
#ifndef _LINUX_MCA_H
#define _LINUX_MCA_H

#include <linux/device.h>

#define MCA_bus 0

typedef int (*MCA_ProcFn)(char* buf, int slot, void* dev);

enum MCA_AdapterStatus {
 MCA_ADAPTER_NORMAL = 0,
 MCA_ADAPTER_NONE = 1,
 MCA_ADAPTER_DISABLED = 2,
 MCA_ADAPTER_ERROR = 3
};

struct mca_device {
 u64 dma_mask;
 int pos_id;
 int slot;

 int index;

 int driver_loaded;

 unsigned char pos[8];

 short pos_register;

 enum MCA_AdapterStatus status;
 struct device dev;
 char name[32];
};
#define to_mca_device(mdev) container_of(mdev, struct mca_device, dev)

struct mca_bus_accessor_functions {
 unsigned char (*mca_read_pos)(struct mca_device *, int reg);
 void (*mca_write_pos)(struct mca_device *, int reg,
 unsigned char byte);
 int (*mca_transform_irq)(struct mca_device *, int irq);
 int (*mca_transform_ioport)(struct mca_device *,
 int region);
 void * (*mca_transform_memory)(struct mca_device *,
 void *memory);
};

struct mca_bus {
 u64 default_dma_mask;
 int number;
 struct mca_bus_accessor_functions f;
 struct device dev;
 char name[32];
};
#define to_mca_bus(mdev) container_of(mdev, struct mca_bus, dev)

struct mca_driver {
 const short *id_table;
 void *driver_data;
 struct device_driver driver;
};
#define to_mca_driver(mdriver) container_of(mdriver, struct mca_driver, driver)

#endif
