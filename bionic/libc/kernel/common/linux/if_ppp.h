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
#ifndef _IF_PPP_H_
#define _IF_PPP_H_

#include <linux/compiler.h>

#define PPP_MTU 1500  
#define PPP_MAXMRU 65000  
#define PROTO_IPX 0x002b  
#define PROTO_DNA_RT 0x0027  

#define SC_COMP_PROT 0x00000001  
#define SC_COMP_AC 0x00000002  
#define SC_COMP_TCP 0x00000004  
#define SC_NO_TCP_CCID 0x00000008  
#define SC_REJ_COMP_AC 0x00000010  
#define SC_REJ_COMP_TCP 0x00000020  
#define SC_CCP_OPEN 0x00000040  
#define SC_CCP_UP 0x00000080  
#define SC_ENABLE_IP 0x00000100  
#define SC_LOOP_TRAFFIC 0x00000200  
#define SC_MULTILINK 0x00000400  
#define SC_MP_SHORTSEQ 0x00000800  
#define SC_COMP_RUN 0x00001000  
#define SC_DECOMP_RUN 0x00002000  
#define SC_MP_XSHORTSEQ 0x00004000  
#define SC_DEBUG 0x00010000  
#define SC_LOG_INPKT 0x00020000  
#define SC_LOG_OUTPKT 0x00040000  
#define SC_LOG_RAWIN 0x00080000  
#define SC_LOG_FLUSH 0x00100000  
#define SC_SYNC 0x00200000  
#define SC_MUST_COMP 0x00400000  
#define SC_MASK 0x0f600fff  

#define SC_XMIT_BUSY 0x10000000  
#define SC_RCV_ODDP 0x08000000  
#define SC_RCV_EVNP 0x04000000  
#define SC_RCV_B7_1 0x02000000  
#define SC_RCV_B7_0 0x01000000  
#define SC_DC_FERROR 0x00800000  
#define SC_DC_ERROR 0x00400000  

struct npioctl {
 int protocol;
 enum NPmode mode;
};

struct ppp_option_data {
 __u8 __user *ptr;
 __u32 length;
 int transmit;
};

struct ifpppstatsreq {
 struct ifreq b;
 struct ppp_stats stats;
};

struct ifpppcstatsreq {
 struct ifreq b;
 struct ppp_comp_stats stats;
};

#define ifr__name b.ifr_ifrn.ifrn_name
#define stats_ptr b.ifr_ifru.ifru_data

#define PPPIOCGFLAGS _IOR('t', 90, int)  
#define PPPIOCSFLAGS _IOW('t', 89, int)  
#define PPPIOCGASYNCMAP _IOR('t', 88, int)  
#define PPPIOCSASYNCMAP _IOW('t', 87, int)  
#define PPPIOCGUNIT _IOR('t', 86, int)  
#define PPPIOCGRASYNCMAP _IOR('t', 85, int)  
#define PPPIOCSRASYNCMAP _IOW('t', 84, int)  
#define PPPIOCGMRU _IOR('t', 83, int)  
#define PPPIOCSMRU _IOW('t', 82, int)  
#define PPPIOCSMAXCID _IOW('t', 81, int)  
#define PPPIOCGXASYNCMAP _IOR('t', 80, ext_accm)  
#define PPPIOCSXASYNCMAP _IOW('t', 79, ext_accm)  
#define PPPIOCXFERUNIT _IO('t', 78)  
#define PPPIOCSCOMPRESS _IOW('t', 77, struct ppp_option_data)
#define PPPIOCGNPMODE _IOWR('t', 76, struct npioctl)  
#define PPPIOCSNPMODE _IOW('t', 75, struct npioctl)  
#define PPPIOCSPASS _IOW('t', 71, struct sock_fprog)  
#define PPPIOCSACTIVE _IOW('t', 70, struct sock_fprog)  
#define PPPIOCGDEBUG _IOR('t', 65, int)  
#define PPPIOCSDEBUG _IOW('t', 64, int)  
#define PPPIOCGIDLE _IOR('t', 63, struct ppp_idle)  
#define PPPIOCNEWUNIT _IOWR('t', 62, int)  
#define PPPIOCATTACH _IOW('t', 61, int)  
#define PPPIOCDETACH _IOW('t', 60, int)  
#define PPPIOCSMRRU _IOW('t', 59, int)  
#define PPPIOCCONNECT _IOW('t', 58, int)  
#define PPPIOCDISCONN _IO('t', 57)  
#define PPPIOCATTCHAN _IOW('t', 56, int)  
#define PPPIOCGCHAN _IOR('t', 55, int)  

#define SIOCGPPPSTATS (SIOCDEVPRIVATE + 0)
#define SIOCGPPPVER (SIOCDEVPRIVATE + 1)  
#define SIOCGPPPCSTATS (SIOCDEVPRIVATE + 2)

#ifndef ifr_mtu
#define ifr_mtu ifr_ifru.ifru_metric
#endif

#endif
