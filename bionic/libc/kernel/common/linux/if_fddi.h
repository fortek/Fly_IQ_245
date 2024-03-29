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
#ifndef _LINUX_IF_FDDI_H
#define _LINUX_IF_FDDI_H

#define FDDI_K_ALEN 6  
#define FDDI_K_8022_HLEN 16  
#define FDDI_K_SNAP_HLEN 21  
#define FDDI_K_8022_ZLEN 16  
#define FDDI_K_SNAP_ZLEN 21  
#define FDDI_K_8022_DLEN 4475  
#define FDDI_K_SNAP_DLEN 4470  
#define FDDI_K_LLC_ZLEN 13  
#define FDDI_K_LLC_LEN 4491  

#define FDDI_FC_K_VOID 0x00 
#define FDDI_FC_K_NON_RESTRICTED_TOKEN 0x80 
#define FDDI_FC_K_RESTRICTED_TOKEN 0xC0 
#define FDDI_FC_K_SMT_MIN 0x41
#define FDDI_FC_K_SMT_MAX 0x4F
#define FDDI_FC_K_MAC_MIN 0xC1
#define FDDI_FC_K_MAC_MAX 0xCF 
#define FDDI_FC_K_ASYNC_LLC_MIN 0x50
#define FDDI_FC_K_ASYNC_LLC_DEF 0x54
#define FDDI_FC_K_ASYNC_LLC_MAX 0x5F
#define FDDI_FC_K_SYNC_LLC_MIN 0xD0
#define FDDI_FC_K_SYNC_LLC_MAX 0xD7
#define FDDI_FC_K_IMPLEMENTOR_MIN 0x60
#define FDDI_FC_K_IMPLEMENTOR_MAX 0x6F
#define FDDI_FC_K_RESERVED_MIN 0x70
#define FDDI_FC_K_RESERVED_MAX 0x7F

#define FDDI_EXTENDED_SAP 0xAA
#define FDDI_UI_CMD 0x03

struct fddi_8022_1_hdr
 {
 __u8 dsap;
 __u8 ssap;
 __u8 ctrl;
 } __attribute__ ((packed));

struct fddi_8022_2_hdr
 {
 __u8 dsap;
 __u8 ssap;
 __u8 ctrl_1;
 __u8 ctrl_2;
 } __attribute__ ((packed));

#define FDDI_K_OUI_LEN 3
struct fddi_snap_hdr
 {
 __u8 dsap;
 __u8 ssap;
 __u8 ctrl;
 __u8 oui[FDDI_K_OUI_LEN];
 __be16 ethertype;
 } __attribute__ ((packed));

struct fddihdr
 {
 __u8 fc;
 __u8 daddr[FDDI_K_ALEN];
 __u8 saddr[FDDI_K_ALEN];
 union
 {
 struct fddi_8022_1_hdr llc_8022_1;
 struct fddi_8022_2_hdr llc_8022_2;
 struct fddi_snap_hdr llc_snap;
 } hdr;
 } __attribute__ ((packed));

#endif
