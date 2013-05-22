/* Copyright Statement:
 * 
 * This software/firmware and related documentation ("MediaTek Software") are 
 * protected under relevant copyright laws. The information contained herein is 
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without 
 * the prior written permission of MediaTek inc. and/or its licensors, any 
 * reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly 
 * prohibited.  
 * 
 * MediaTek Inc. (C) 2010. All rights reserved.
 * 
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES 
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") 
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON 
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER 
 * DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE SOFTWARE OF 
 * ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR SUPPLIED WITH THE 
 * MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH THIRD PARTY FOR 
 * ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT 
 * IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER 
 * LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE 
 * RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S 
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM. 
 * RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE 
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, 
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
#ifndef __ASM_SH_MIGOR_H
#define __ASM_SH_MIGOR_H

#include <asm/addrspace.h>

#define PORT_PACR 0xa4050100
#define PORT_PDCR 0xa4050106
#define PORT_PECR 0xa4050108
#define PORT_PHCR 0xa405010e
#define PORT_PJCR 0xa4050110
#define PORT_PKCR 0xa4050112
#define PORT_PLCR 0xa4050114
#define PORT_PMCR 0xa4050116
#define PORT_PRCR 0xa405011c
#define PORT_PTCR 0xa4050140
#define PORT_PUCR 0xa4050142
#define PORT_PVCR 0xa4050144
#define PORT_PWCR 0xa4050146
#define PORT_PXCR 0xa4050148
#define PORT_PYCR 0xa405014a
#define PORT_PZCR 0xa405014c
#define PORT_PADR 0xa4050120
#define PORT_PHDR 0xa405012e
#define PORT_PTDR 0xa4050160
#define PORT_PWDR 0xa4050166

#define PORT_HIZCRA 0xa4050158
#define PORT_HIZCRC 0xa405015c

#define PORT_MSELCRB 0xa4050182

#define PORT_PSELA 0xa405014e
#define PORT_PSELB 0xa4050150
#define PORT_PSELC 0xa4050152
#define PORT_PSELD 0xa4050154
#define PORT_PSELE 0xa4050156

#define PORT_HIZCRA 0xa4050158
#define PORT_HIZCRB 0xa405015a
#define PORT_HIZCRC 0xa405015c

#define BSC_CS6ABCR 0xfec1001c

#include <asm/sh_mobile_lcdc.h>

#endif
