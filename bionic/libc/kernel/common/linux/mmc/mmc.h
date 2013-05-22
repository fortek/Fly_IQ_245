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
#ifndef MMC_H
#define MMC_H

#include <linux/list.h>
#include <linux/interrupt.h>
#include <linux/device.h>

struct request;
struct mmc_data;
struct mmc_request;

struct mmc_command {
 u32 opcode;
 u32 arg;
 u32 resp[4];
 unsigned int flags;
#define MMC_RSP_PRESENT (1 << 0)
#define MMC_RSP_136 (1 << 1)  
#define MMC_RSP_CRC (1 << 2)  
#define MMC_RSP_BUSY (1 << 3)  
#define MMC_RSP_OPCODE (1 << 4)  
#define MMC_CMD_MASK (3 << 5)  
#define MMC_CMD_AC (0 << 5)
#define MMC_CMD_ADTC (1 << 5)
#define MMC_CMD_BC (2 << 5)
#define MMC_CMD_BCR (3 << 5)

#define MMC_RSP_NONE (0)
#define MMC_RSP_R1 (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE)
#define MMC_RSP_R1B (MMC_RSP_PRESENT|MMC_RSP_CRC|MMC_RSP_OPCODE|MMC_RSP_BUSY)
#define MMC_RSP_R2 (MMC_RSP_PRESENT|MMC_RSP_136|MMC_RSP_CRC)
#define MMC_RSP_R3 (MMC_RSP_PRESENT)
#define MMC_RSP_R6 (MMC_RSP_PRESENT|MMC_RSP_CRC)

#define mmc_resp_type(cmd) ((cmd)->flags & (MMC_RSP_PRESENT|MMC_RSP_136|MMC_RSP_CRC|MMC_RSP_BUSY|MMC_RSP_OPCODE))

#define mmc_cmd_type(cmd) ((cmd)->flags & MMC_CMD_MASK)

 unsigned int retries;
 unsigned int error;

#define MMC_ERR_NONE 0
#define MMC_ERR_TIMEOUT 1
#define MMC_ERR_BADCRC 2
#define MMC_ERR_FIFO 3
#define MMC_ERR_FAILED 4
#define MMC_ERR_INVALID 5

 struct mmc_data *data;
 struct mmc_request *mrq;
};

struct mmc_data {
 unsigned int timeout_ns;
 unsigned int timeout_clks;
 unsigned int blksz_bits;
 unsigned int blksz;
 unsigned int blocks;
 unsigned int error;
 unsigned int flags;

#define MMC_DATA_WRITE (1 << 8)
#define MMC_DATA_READ (1 << 9)
#define MMC_DATA_STREAM (1 << 10)
#define MMC_DATA_MULTI (1 << 11)

 unsigned int bytes_xfered;

 struct mmc_command *stop;
 struct mmc_request *mrq;

 unsigned int sg_len;
 struct scatterlist *sg;
};

struct mmc_request {
 struct mmc_command *cmd;
 struct mmc_data *data;
 struct mmc_command *stop;

 void *done_data;
 void (*done)(struct mmc_request *);
};

struct mmc_host;
struct mmc_card;

#endif
