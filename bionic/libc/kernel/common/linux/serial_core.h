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
#ifndef LINUX_SERIAL_CORE_H
#define LINUX_SERIAL_CORE_H

#define PORT_UNKNOWN 0
#define PORT_8250 1
#define PORT_16450 2
#define PORT_16550 3
#define PORT_16550A 4
#define PORT_CIRRUS 5
#define PORT_16650 6
#define PORT_16650V2 7
#define PORT_16750 8
#define PORT_STARTECH 9
#define PORT_16C950 10
#define PORT_16654 11
#define PORT_16850 12
#define PORT_RSA 13
#define PORT_NS16550A 14
#define PORT_XSCALE 15
#define PORT_MAX_8250 15  

#define PORT_PXA 31
#define PORT_AMBA 32
#define PORT_CLPS711X 33
#define PORT_SA1100 34
#define PORT_UART00 35
#define PORT_21285 37

#define PORT_SUNZILOG 38
#define PORT_SUNSAB 39

#define PORT_V850E_UART 40

#define PORT_DZ 47

#define PORT_MUX 48

#define PORT_AT91 49

#define PORT_MAC_ZILOG 50  
#define PORT_PMAC_ZILOG 51

#define PORT_SCI 52
#define PORT_SCIF 53
#define PORT_IRDA 54

#define PORT_S3C2410 55

#define PORT_IP22ZILOG 56

#define PORT_LH7A40X 57

#define PORT_CPM 58

#define PORT_MPC52xx 59

#define PORT_ICOM 60

#define PORT_S3C2440 61

#define PORT_IMX 62

#define PORT_MPSC 63

#define PORT_TXX9 64

#define PORT_VR41XX_SIU 65
#define PORT_VR41XX_DSIU 66

#define PORT_S3C2400 67

#define PORT_M32R_SIO 68

#define PORT_JSM 69

#define PORT_IP3106 70

#define PORT_NETX 71

#define PORT_SUNHV 72

#define PORT_S3C2412 73

#endif
