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
#ifndef _LINUX_IF_LINK_H
#define _LINUX_IF_LINK_H

#include <linux/types.h>
#include <linux/netlink.h>

struct rtnl_link_stats
{
 __u32 rx_packets;
 __u32 tx_packets;
 __u32 rx_bytes;
 __u32 tx_bytes;
 __u32 rx_errors;
 __u32 tx_errors;
 __u32 rx_dropped;
 __u32 tx_dropped;
 __u32 multicast;
 __u32 collisions;

 __u32 rx_length_errors;
 __u32 rx_over_errors;
 __u32 rx_crc_errors;
 __u32 rx_frame_errors;
 __u32 rx_fifo_errors;
 __u32 rx_missed_errors;

 __u32 tx_aborted_errors;
 __u32 tx_carrier_errors;
 __u32 tx_fifo_errors;
 __u32 tx_heartbeat_errors;
 __u32 tx_window_errors;

 __u32 rx_compressed;
 __u32 tx_compressed;
};

struct rtnl_link_ifmap
{
 __u64 mem_start;
 __u64 mem_end;
 __u64 base_addr;
 __u16 irq;
 __u8 dma;
 __u8 port;
};

enum
{
 IFLA_UNSPEC,
 IFLA_ADDRESS,
 IFLA_BROADCAST,
 IFLA_IFNAME,
 IFLA_MTU,
 IFLA_LINK,
 IFLA_QDISC,
 IFLA_STATS,
 IFLA_COST,
#define IFLA_COST IFLA_COST
 IFLA_PRIORITY,
#define IFLA_PRIORITY IFLA_PRIORITY
 IFLA_MASTER,
#define IFLA_MASTER IFLA_MASTER
 IFLA_WIRELESS,
#define IFLA_WIRELESS IFLA_WIRELESS
 IFLA_PROTINFO,
#define IFLA_PROTINFO IFLA_PROTINFO
 IFLA_TXQLEN,
#define IFLA_TXQLEN IFLA_TXQLEN
 IFLA_MAP,
#define IFLA_MAP IFLA_MAP
 IFLA_WEIGHT,
#define IFLA_WEIGHT IFLA_WEIGHT
 IFLA_OPERSTATE,
 IFLA_LINKMODE,
 IFLA_LINKINFO,
#define IFLA_LINKINFO IFLA_LINKINFO
 IFLA_NET_NS_PID,
 IFLA_IFALIAS,
 __IFLA_MAX
};

#define IFLA_MAX (__IFLA_MAX - 1)

#define IFLA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct ifinfomsg))))
#define IFLA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct ifinfomsg))

enum
{
 IFLA_INET6_UNSPEC,
 IFLA_INET6_FLAGS,
 IFLA_INET6_CONF,
 IFLA_INET6_STATS,
 IFLA_INET6_MCAST,
 IFLA_INET6_CACHEINFO,
 IFLA_INET6_ICMP6STATS,
 __IFLA_INET6_MAX
};

#define IFLA_INET6_MAX (__IFLA_INET6_MAX - 1)

struct ifla_cacheinfo
{
 __u32 max_reasm_len;
 __u32 tstamp;
 __u32 reachable_time;
 __u32 retrans_time;
};

enum
{
 IFLA_INFO_UNSPEC,
 IFLA_INFO_KIND,
 IFLA_INFO_DATA,
 IFLA_INFO_XSTATS,
 __IFLA_INFO_MAX,
};

#define IFLA_INFO_MAX (__IFLA_INFO_MAX - 1)

enum
{
 IFLA_VLAN_UNSPEC,
 IFLA_VLAN_ID,
 IFLA_VLAN_FLAGS,
 IFLA_VLAN_EGRESS_QOS,
 IFLA_VLAN_INGRESS_QOS,
 __IFLA_VLAN_MAX,
};

#define IFLA_VLAN_MAX (__IFLA_VLAN_MAX - 1)

struct ifla_vlan_flags {
 __u32 flags;
 __u32 mask;
};

enum
{
 IFLA_VLAN_QOS_UNSPEC,
 IFLA_VLAN_QOS_MAPPING,
 __IFLA_VLAN_QOS_MAX
};

#define IFLA_VLAN_QOS_MAX (__IFLA_VLAN_QOS_MAX - 1)

struct ifla_vlan_qos_mapping
{
 __u32 from;
 __u32 to;
};

#endif
