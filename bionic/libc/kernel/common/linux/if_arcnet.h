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
#ifndef _LINUX_IF_ARCNET_H
#define _LINUX_IF_ARCNET_H

#include <linux/if_ether.h>

#define ARC_P_IP 212  
#define ARC_P_IPV6 196  
#define ARC_P_ARP 213  
#define ARC_P_RARP 214  
#define ARC_P_IPX 250  
#define ARC_P_NOVELL_EC 236  

#define ARC_P_IP_RFC1051 240  
#define ARC_P_ARP_RFC1051 241  

#define ARC_P_ETHER 232  

#define ARC_P_DATAPOINT_BOOT 0  
#define ARC_P_DATAPOINT_MOUNT 1
#define ARC_P_POWERLAN_BEACON 8  
#define ARC_P_POWERLAN_BEACON2 243  
#define ARC_P_LANSOFT 251  
#define ARC_P_ATALK 0xDD

#define ARCNET_ALEN 1

struct arc_rfc1201
{
 uint8_t proto;
 uint8_t split_flag;
 uint16_t sequence;
 uint8_t payload[0];
};
#define RFC1201_HDR_SIZE 4

struct arc_rfc1051
{
 uint8_t proto;
 uint8_t payload[0];
};
#define RFC1051_HDR_SIZE 1

struct arc_eth_encap
{
 uint8_t proto;
 struct ethhdr eth;
 uint8_t payload[0];
};
#define ETH_ENCAP_HDR_SIZE 14

struct arc_cap
{
 uint8_t proto;
 uint8_t cookie[sizeof(int)];
 union {
 uint8_t ack;
 uint8_t raw[0];
 } mes;
};

struct arc_hardware
{
 uint8_t source,
 dest,
 offset[2];
};
#define ARC_HDR_SIZE 4

struct archdr
{

 struct arc_hardware hard;

 union {
 struct arc_rfc1201 rfc1201;
 struct arc_rfc1051 rfc1051;
 struct arc_eth_encap eth_encap;
 struct arc_cap cap;
 uint8_t raw[0];
 } soft;
};

#endif