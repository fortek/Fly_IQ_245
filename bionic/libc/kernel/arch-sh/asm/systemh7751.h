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
#ifndef __ASM_SH_SYSTEMH_7751SYSTEMH_H
#define __ASM_SH_SYSTEMH_7751SYSTEMH_H

#define PA_ROM 0x00000000  
#define PA_ROM_SIZE 0x00400000  
#define PA_FROM 0x01000000  
#define PA_FROM_SIZE 0x00400000  
#define PA_EXT1 0x04000000
#define PA_EXT1_SIZE 0x04000000
#define PA_EXT2 0x08000000
#define PA_EXT2_SIZE 0x04000000
#define PA_SDRAM 0x0c000000
#define PA_SDRAM_SIZE 0x04000000

#define PA_EXT4 0x12000000
#define PA_EXT4_SIZE 0x02000000
#define PA_EXT5 0x14000000
#define PA_EXT5_SIZE 0x04000000
#define PA_PCIC 0x18000000  

#define PA_DIPSW0 0xb9000000  
#define PA_DIPSW1 0xb9000002  
#define PA_LED 0xba000000  
#define PA_BCR 0xbb000000  

#define PA_MRSHPC 0xb83fffe0  
#define PA_MRSHPC_MW1 0xb8400000  
#define PA_MRSHPC_MW2 0xb8500000  
#define PA_MRSHPC_IO 0xb8600000  
#define MRSHPC_MODE (PA_MRSHPC + 4)
#define MRSHPC_OPTION (PA_MRSHPC + 6)
#define MRSHPC_CSR (PA_MRSHPC + 8)
#define MRSHPC_ISR (PA_MRSHPC + 10)
#define MRSHPC_ICR (PA_MRSHPC + 12)
#define MRSHPC_CPWCR (PA_MRSHPC + 14)
#define MRSHPC_MW0CR1 (PA_MRSHPC + 16)
#define MRSHPC_MW1CR1 (PA_MRSHPC + 18)
#define MRSHPC_IOWCR1 (PA_MRSHPC + 20)
#define MRSHPC_MW0CR2 (PA_MRSHPC + 22)
#define MRSHPC_MW1CR2 (PA_MRSHPC + 24)
#define MRSHPC_IOWCR2 (PA_MRSHPC + 26)
#define MRSHPC_CDCR (PA_MRSHPC + 28)
#define MRSHPC_PCIC_INFO (PA_MRSHPC + 30)

#define BCR_ILCRA (PA_BCR + 0)
#define BCR_ILCRB (PA_BCR + 2)
#define BCR_ILCRC (PA_BCR + 4)
#define BCR_ILCRD (PA_BCR + 6)
#define BCR_ILCRE (PA_BCR + 8)
#define BCR_ILCRF (PA_BCR + 10)
#define BCR_ILCRG (PA_BCR + 12)

#define IRQ_79C973 13

#define __IO_PREFIX sh7751systemh
#include <asm/io_generic.h>

#endif
