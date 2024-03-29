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
#ifndef _LINUX_VT_H
#define _LINUX_VT_H

#define MIN_NR_CONSOLES 1  
#define MAX_NR_CONSOLES 63  
#define MAX_NR_USER_CONSOLES 63  

#define VT_OPENQRY 0x5600  

struct vt_mode {
 char mode;
 char waitv;
 short relsig;
 short acqsig;
 short frsig;
};
#define VT_GETMODE 0x5601  
#define VT_SETMODE 0x5602  
#define VT_AUTO 0x00  
#define VT_PROCESS 0x01  
#define VT_ACKACQ 0x02  

struct vt_stat {
 unsigned short v_active;
 unsigned short v_signal;
 unsigned short v_state;
};
#define VT_GETSTATE 0x5603  
#define VT_SENDSIG 0x5604  

#define VT_RELDISP 0x5605  

#define VT_ACTIVATE 0x5606  
#define VT_WAITACTIVE 0x5607  
#define VT_DISALLOCATE 0x5608  

struct vt_sizes {
 unsigned short v_rows;
 unsigned short v_cols;
 unsigned short v_scrollsize;
};
#define VT_RESIZE 0x5609  

struct vt_consize {
 unsigned short v_rows;
 unsigned short v_cols;
 unsigned short v_vlin;
 unsigned short v_clin;
 unsigned short v_vcol;
 unsigned short v_ccol;
};
#define VT_RESIZEX 0x560A  
#define VT_LOCKSWITCH 0x560B  
#define VT_UNLOCKSWITCH 0x560C  
#define VT_GETHIFONTMASK 0x560D  

#endif
