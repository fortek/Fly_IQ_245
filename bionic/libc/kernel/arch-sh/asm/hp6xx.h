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
#ifndef __ASM_SH_HP6XX_H
#define __ASM_SH_HP6XX_H

#define HP680_BTN_IRQ 32  
#define HP680_TS_IRQ 35  
#define HP680_HD64461_IRQ 36  

#define DAC_LCD_BRIGHTNESS 0
#define DAC_SPEAKER_VOLUME 1

#define PGDR_OPENED 0x01
#define PGDR_MAIN_BATTERY_OUT 0x04
#define PGDR_PLAY_BUTTON 0x08
#define PGDR_REWIND_BUTTON 0x10
#define PGDR_RECORD_BUTTON 0x20

#define PHDR_TS_PEN_DOWN 0x08

#define PJDR_LED_BLINK 0x02

#define PKDR_LED_GREEN 0x10

#define SCPDR_TS_SCAN_ENABLE 0x20
#define SCPDR_TS_SCAN_Y 0x02
#define SCPDR_TS_SCAN_X 0x01

#define SCPCR_TS_ENABLE 0x405
#define SCPCR_TS_MASK 0xc0f

#define ADC_CHANNEL_TS_Y 1
#define ADC_CHANNEL_TS_X 2
#define ADC_CHANNEL_BATTERY 3
#define ADC_CHANNEL_BACKUP 4
#define ADC_CHANNEL_CHARGE 5

#define HD64461_GPADR_SPEAKER 0x01
#define HD64461_GPADR_PCMCIA0 (0x02|0x08)

#define HD64461_GPBDR_LCDOFF 0x01
#define HD64461_GPBDR_LCD_CONTRAST_MASK 0x78
#define HD64461_GPBDR_LED_RED 0x80

#include <asm/hd64461.h>
#include <asm/io.h>

#define PJDR 0xa4000130
#define PKDR 0xa4000132

#endif
