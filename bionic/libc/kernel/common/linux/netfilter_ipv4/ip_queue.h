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
#ifndef _IP_QUEUE_H
#define _IP_QUEUE_H

#include <net/if.h>

typedef struct ipq_packet_msg {
 unsigned long packet_id;
 unsigned long mark;
 long timestamp_sec;
 long timestamp_usec;
 unsigned int hook;
 char indev_name[IFNAMSIZ];
 char outdev_name[IFNAMSIZ];
 unsigned short hw_protocol;
 unsigned short hw_type;
 unsigned char hw_addrlen;
 unsigned char hw_addr[8];
 size_t data_len;
 unsigned char payload[0];
} ipq_packet_msg_t;

typedef struct ipq_mode_msg {
 unsigned char value;
 size_t range;
} ipq_mode_msg_t;

typedef struct ipq_verdict_msg {
 unsigned int value;
 unsigned long id;
 size_t data_len;
 unsigned char payload[0];
} ipq_verdict_msg_t;

typedef struct ipq_peer_msg {
 union {
 ipq_verdict_msg_t verdict;
 ipq_mode_msg_t mode;
 } msg;
} ipq_peer_msg_t;

enum {
 IPQ_COPY_NONE,
 IPQ_COPY_META,
 IPQ_COPY_PACKET
};
#define IPQ_COPY_MAX IPQ_COPY_PACKET

#define IPQM_BASE 0x10  
#define IPQM_MODE (IPQM_BASE + 1)  
#define IPQM_VERDICT (IPQM_BASE + 2)   
#define IPQM_PACKET (IPQM_BASE + 3)  
#define IPQM_MAX (IPQM_BASE + 4)

#endif
