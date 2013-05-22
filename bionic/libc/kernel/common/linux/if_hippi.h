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
#ifndef _LINUX_IF_HIPPI_H
#define _LINUX_IF_HIPPI_H

#include <asm/byteorder.h>

#define HIPPI_ALEN 6  
#define HIPPI_HLEN sizeof(struct hippi_hdr)
#define HIPPI_ZLEN 0  
#define HIPPI_DATA_LEN 65280  
#define HIPPI_FRAME_LEN (HIPPI_DATA_LEN + HIPPI_HLEN)

#define HIPPI_EXTENDED_SAP 0xAA
#define HIPPI_UI_CMD 0x03

struct hipnet_statistics
{
 int rx_packets;
 int tx_packets;
 int rx_errors;
 int tx_errors;
 int rx_dropped;
 int tx_dropped;

 int rx_length_errors;
 int rx_over_errors;
 int rx_crc_errors;
 int rx_frame_errors;
 int rx_fifo_errors;
 int rx_missed_errors;

 int tx_aborted_errors;
 int tx_carrier_errors;
 int tx_fifo_errors;
 int tx_heartbeat_errors;
 int tx_window_errors;
};

struct hippi_fp_hdr
{
 __be32 fixed;
 __be32 d2_size;
} __attribute__ ((packed));

struct hippi_le_hdr
{
#ifdef __BIG_ENDIAN_BITFIELD
 __u8 fc:3;
 __u8 double_wide:1;
 __u8 message_type:4;
#elif defined(__LITTLE_ENDIAN_BITFIELD)
 __u8 message_type:4;
 __u8 double_wide:1;
 __u8 fc:3;
#endif
 __u8 dest_switch_addr[3];
#ifdef __BIG_ENDIAN_BITFIELD
 __u8 dest_addr_type:4,
 src_addr_type:4;
#elif defined(__LITTLE_ENDIAN_BITFIELD)
 __u8 src_addr_type:4,
 dest_addr_type:4;
#endif
 __u8 src_switch_addr[3];
 __u16 reserved;
 __u8 daddr[HIPPI_ALEN];
 __u16 locally_administered;
 __u8 saddr[HIPPI_ALEN];
} __attribute__ ((packed));

#define HIPPI_OUI_LEN 3

struct hippi_snap_hdr
{
 __u8 dsap;
 __u8 ssap;
 __u8 ctrl;
 __u8 oui[HIPPI_OUI_LEN];
 __be16 ethertype;
} __attribute__ ((packed));

struct hippi_hdr
{
 struct hippi_fp_hdr fp;
 struct hippi_le_hdr le;
 struct hippi_snap_hdr snap;
} __attribute__ ((packed));

#endif
