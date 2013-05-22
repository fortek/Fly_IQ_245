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
#ifndef _LINUX_IF_ARP_H
#define _LINUX_IF_ARP_H

#include <linux/netdevice.h>

#define ARPHRD_NETROM 0  
#define ARPHRD_ETHER 1  
#define ARPHRD_EETHER 2  
#define ARPHRD_AX25 3  
#define ARPHRD_PRONET 4  
#define ARPHRD_CHAOS 5  
#define ARPHRD_IEEE802 6  
#define ARPHRD_ARCNET 7  
#define ARPHRD_APPLETLK 8  
#define ARPHRD_DLCI 15  
#define ARPHRD_ATM 19  
#define ARPHRD_METRICOM 23  
#define ARPHRD_IEEE1394 24  
#define ARPHRD_EUI64 27  
#define ARPHRD_INFINIBAND 32  

#define ARPHRD_SLIP 256
#define ARPHRD_CSLIP 257
#define ARPHRD_SLIP6 258
#define ARPHRD_CSLIP6 259
#define ARPHRD_RSRVD 260  
#define ARPHRD_ADAPT 264
#define ARPHRD_ROSE 270
#define ARPHRD_X25 271  
#define ARPHRD_HWX25 272  
#define ARPHRD_CAN 280  
#define ARPHRD_PPP 512
#define ARPHRD_CISCO 513  
#define ARPHRD_HDLC ARPHRD_CISCO
#define ARPHRD_LAPB 516  
#define ARPHRD_DDCMP 517  
#define ARPHRD_RAWHDLC 518  

#define ARPHRD_TUNNEL 768  
#define ARPHRD_TUNNEL6 769  
#define ARPHRD_FRAD 770  
#define ARPHRD_SKIP 771  
#define ARPHRD_LOOPBACK 772  
#define ARPHRD_LOCALTLK 773  
#define ARPHRD_FDDI 774  
#define ARPHRD_BIF 775  
#define ARPHRD_SIT 776  
#define ARPHRD_IPDDP 777  
#define ARPHRD_IPGRE 778  
#define ARPHRD_PIMREG 779  
#define ARPHRD_HIPPI 780  
#define ARPHRD_ASH 781  
#define ARPHRD_ECONET 782  
#define ARPHRD_IRDA 783  

#define ARPHRD_FCPP 784  
#define ARPHRD_FCAL 785  
#define ARPHRD_FCPL 786  
#define ARPHRD_FCFABRIC 787  

#define ARPHRD_IEEE802_TR 800  
#define ARPHRD_IEEE80211 801  
#define ARPHRD_IEEE80211_PRISM 802  
#define ARPHRD_IEEE80211_RADIOTAP 803  
#define ARPHRD_IEEE802154 804

#define ARPHRD_PHONET 820  
#define ARPHRD_PHONET_PIPE 821  

#define ARPHRD_VOID 0xFFFF  
#define ARPHRD_NONE 0xFFFE  

#define ARPOP_REQUEST 1  
#define ARPOP_REPLY 2  
#define ARPOP_RREQUEST 3  
#define ARPOP_RREPLY 4  
#define ARPOP_InREQUEST 8  
#define ARPOP_InREPLY 9  
#define ARPOP_NAK 10  

struct arpreq {
 struct sockaddr arp_pa;
 struct sockaddr arp_ha;
 int arp_flags;
 struct sockaddr arp_netmask;
 char arp_dev[16];
};

struct arpreq_old {
 struct sockaddr arp_pa;
 struct sockaddr arp_ha;
 int arp_flags;
 struct sockaddr arp_netmask;
};

#define ATF_COM 0x02  
#define ATF_PERM 0x04  
#define ATF_PUBL 0x08  
#define ATF_USETRAILERS 0x10  
#define ATF_NETMASK 0x20  
#define ATF_DONTPUB 0x40  

struct arphdr
{
 __be16 ar_hrd;
 __be16 ar_pro;
 unsigned char ar_hln;
 unsigned char ar_pln;
 __be16 ar_op;

};

#endif
