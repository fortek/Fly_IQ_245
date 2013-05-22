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
#ifndef _LINUX_ATMSAP_H
#define _LINUX_ATMSAP_H

#include <linux/atmapi.h>

#define ATM_L2_NONE 0  
#define ATM_L2_ISO1745 0x01  
#define ATM_L2_Q291 0x02  
#define ATM_L2_X25_LL 0x06  
#define ATM_L2_X25_ML 0x07  
#define ATM_L2_LAPB 0x08  
#define ATM_L2_HDLC_ARM 0x09  
#define ATM_L2_HDLC_NRM 0x0a  
#define ATM_L2_HDLC_ABM 0x0b  
#define ATM_L2_ISO8802 0x0c  
#define ATM_L2_X75 0x0d  
#define ATM_L2_Q922 0x0e  
#define ATM_L2_USER 0x10  
#define ATM_L2_ISO7776 0x11  

#define ATM_L3_NONE 0  
#define ATM_L3_X25 0x06  
#define ATM_L3_ISO8208 0x07  
#define ATM_L3_X223 0x08  
#define ATM_L3_ISO8473 0x09  
#define ATM_L3_T70 0x0a  
#define ATM_L3_TR9577 0x0b  
#define ATM_L3_H310 0x0c  
#define ATM_L3_H321 0x0d  
#define ATM_L3_USER 0x10  

#define ATM_HL_NONE 0  
#define ATM_HL_ISO 0x01  
#define ATM_HL_USER 0x02  
#define ATM_HL_HLP 0x03  
#define ATM_HL_VENDOR 0x04  

#define ATM_IMD_NONE 0  
#define ATM_IMD_NORMAL 1  
#define ATM_IMD_EXTENDED 2  

#define ATM_TT_NONE 0  
#define ATM_TT_RX 1  
#define ATM_TT_TX 2  
#define ATM_TT_RXTX 3  

#define ATM_MC_NONE 0  
#define ATM_MC_TS 1  
#define ATM_MC_TS_FEC 2  
#define ATM_MC_PS 3  
#define ATM_MC_PS_FEC 4  
#define ATM_MC_H221 5  

#define ATM_MAX_HLI 8  

struct atm_blli {
 unsigned char l2_proto;
 union {
 struct {
 unsigned char mode;

 unsigned char window;
 } itu;
 unsigned char user;
 } l2;
 unsigned char l3_proto;
 union {
 struct {
 unsigned char mode;

 unsigned char def_size;

 unsigned char window;
 } itu;
 unsigned char user;
 struct {
 unsigned char term_type;
 unsigned char fw_mpx_cap;

 unsigned char bw_mpx_cap;

 } h310;
 struct {
 unsigned char ipi;
 unsigned char snap[5];

 } tr9577;
 } l3;
} __ATM_API_ALIGN;

struct atm_bhli {
 unsigned char hl_type;
 unsigned char hl_length;

 unsigned char hl_info[ATM_MAX_HLI];
};

#define ATM_MAX_BLLI 3  

struct atm_sap {
 struct atm_bhli bhli;
 struct atm_blli blli[ATM_MAX_BLLI] __ATM_API_ALIGN;

};

#endif
