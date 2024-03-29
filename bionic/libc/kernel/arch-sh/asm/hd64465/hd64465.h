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
#ifndef _ASM_SH_HD64465_
#define _ASM_SH_HD64465_ 1

#include <asm/io.h>
#include <asm/irq.h>

#define HD64465_REG_SRR 0x1000c  
#define HD64465_REG_SDID 0x10010  
#define HD64465_SDID 0x8122  

#define HD64465_REG_SMSCR 0x10000  
#define HD64465_SMSCR_PS2ST 0x4000  
#define HD64465_SMSCR_ADCST 0x1000  
#define HD64465_SMSCR_UARTST 0x0800  
#define HD64465_SMSCR_SCDIST 0x0200  
#define HD64465_SMSCR_PPST 0x0100  
#define HD64465_SMSCR_PC0ST 0x0040  
#define HD64465_SMSCR_PC1ST 0x0020  
#define HD64465_SMSCR_AFEST 0x0010  
#define HD64465_SMSCR_TM0ST 0x0008  
#define HD64465_SMSCR_TM1ST 0x0004  
#define HD64465_SMSCR_IRDAST 0x0002  
#define HD64465_SMSCR_KBCST 0x0001  

#define HD64465_REG_NIRR 0x15000  
#define HD64465_REG_NIMR 0x15002  
#define HD64465_REG_NITR 0x15004  

#define HD64465_REG_TCVR1 0x16000  
#define HD64465_REG_TCVR0 0x16002  
#define HD64465_REG_TRVR1 0x16004  
#define HD64465_REG_TRVR0 0x16006  
#define HD64465_REG_TCR1 0x16008  
#define HD64465_REG_TCR0 0x1600A  
#define HD64465_TCR_EADT 0x10  
#define HD64465_TCR_ETMO 0x08  
#define HD64465_TCR_PST_MASK 0x06  
#define HD64465_TCR_PST_1 0x06  
#define HD64465_TCR_PST_4 0x04  
#define HD64465_TCR_PST_8 0x02  
#define HD64465_TCR_PST_16 0x00  
#define HD64465_TCR_TSTP 0x01  
#define HD64465_REG_TIRR 0x1600C  
#define HD64465_REG_TIDR 0x1600E  
#define HD64465_REG_PWM1CS 0x16010  
#define HD64465_REG_PWM1LPC 0x16012  
#define HD64465_REG_PWM1HPC 0x16014  
#define HD64465_REG_PWM0CS 0x16018  
#define HD64465_REG_PWM0LPC 0x1601A  
#define HD64465_REG_PWM0HPC 0x1601C  

#define HD64465_REG_ADDRA 0x1E000  
#define HD64465_REG_ADDRB 0x1E002  
#define HD64465_REG_ADDRC 0x1E004  
#define HD64465_REG_ADDRD 0x1E006  
#define HD64465_REG_ADCSR 0x1E008  
#define HD64465_ADCSR_ADF 0x80  
#define HD64465_ADCSR_ADST 0x40  
#define HD64465_ADCSR_ADIS 0x20  
#define HD64465_ADCSR_TRGE 0x10  
#define HD64465_ADCSR_ADIE 0x08  
#define HD64465_ADCSR_SCAN 0x04  
#define HD64465_ADCSR_CH_MASK 0x03  
#define HD64465_REG_ADCALCR 0x1E00A  
#define HD64465_REG_ADCAL 0x1E00C  

#define HD64465_REG_GPACR 0x14000  
#define HD64465_REG_GPBCR 0x14002  
#define HD64465_REG_GPCCR 0x14004  
#define HD64465_REG_GPDCR 0x14006  
#define HD64465_REG_GPECR 0x14008  
#define HD64465_REG_GPADR 0x14010  
#define HD64465_REG_GPBDR 0x14012  
#define HD64465_REG_GPCDR 0x14014  
#define HD64465_REG_GPDDR 0x14016  
#define HD64465_REG_GPEDR 0x14018  
#define HD64465_REG_GPAICR 0x14020  
#define HD64465_REG_GPBICR 0x14022  
#define HD64465_REG_GPCICR 0x14024  
#define HD64465_REG_GPDICR 0x14026  
#define HD64465_REG_GPEICR 0x14028  
#define HD64465_REG_GPAISR 0x14040  
#define HD64465_REG_GPBISR 0x14042  
#define HD64465_REG_GPCISR 0x14044  
#define HD64465_REG_GPDISR 0x14046  
#define HD64465_REG_GPEISR 0x14048  

#define HD64465_REG_PCC0ISR 0x12000   
#define HD64465_PCCISR_PREADY 0x80  
#define HD64465_PCCISR_PIREQ 0x80
#define HD64465_PCCISR_PMWP 0x40  
#define HD64465_PCCISR_PVS2 0x20  
#define HD64465_PCCISR_PVS1 0x10  
#define HD64465_PCCISR_PCD_MASK 0x0c  
#define HD64465_PCCISR_PBVD_MASK 0x03  
#define HD64465_PCCISR_PBVD_BATGOOD 0x03  
#define HD64465_PCCISR_PBVD_BATWARN 0x01  
#define HD64465_PCCISR_PBVD_BATDEAD1 0x02  
#define HD64465_PCCISR_PBVD_BATDEAD2 0x00  
#define HD64465_REG_PCC0GCR 0x12002   
#define HD64465_PCCGCR_PDRV 0x80  
#define HD64465_PCCGCR_PCCR 0x40  
#define HD64465_PCCGCR_PCCT 0x20  
#define HD64465_PCCGCR_PVCC0 0x10  
#define HD64465_PCCGCR_PMMOD 0x08  
#define HD64465_PCCGCR_PPA25 0x04  
#define HD64465_PCCGCR_PPA24 0x02  
#define HD64465_PCCGCR_PREG 0x01  
#define HD64465_REG_PCC0CSCR 0x12004   
#define HD64465_PCCCSCR_PSCDI 0x80  
#define HD64465_PCCCSCR_PSWSEL 0x40  
#define HD64465_PCCCSCR_PIREQ 0x20  
#define HD64465_PCCCSCR_PSC 0x10  
#define HD64465_PCCCSCR_PCDC 0x08  
#define HD64465_PCCCSCR_PRC 0x04  
#define HD64465_PCCCSCR_PBW 0x02  
#define HD64465_PCCCSCR_PBD 0x01  
#define HD64465_REG_PCC0CSCIER 0x12006   
#define HD64465_PCCCSCIER_PCRE 0x80  
#define HD64465_PCCCSCIER_PIREQE_MASK 0x60  
#define HD64465_PCCCSCIER_PIREQE_DISABLED 0x00  
#define HD64465_PCCCSCIER_PIREQE_LEVEL 0x20  
#define HD64465_PCCCSCIER_PIREQE_FALLING 0x40  
#define HD64465_PCCCSCIER_PIREQE_RISING 0x60  
#define HD64465_PCCCSCIER_PSCE 0x10  
#define HD64465_PCCCSCIER_PCDE 0x08  
#define HD64465_PCCCSCIER_PRE 0x04  
#define HD64465_PCCCSCIER_PBWE 0x02  
#define HD64465_PCCCSCIER_PBDE 0x01  
#define HD64465_REG_PCC0SCR 0x12008   
#define HD64465_PCCSCR_SHDN 0x10  
#define HD64465_PCCSCR_SWP 0x01  
#define HD64465_REG_PCCPSR 0x1200A   
#define HD64465_REG_PCC1ISR 0x12010   
#define HD64465_REG_PCC1GCR 0x12012   
#define HD64465_REG_PCC1CSCR 0x12014   
#define HD64465_REG_PCC1CSCIER 0x12016   
#define HD64465_REG_PCC1SCR 0x12018   

#define HD64465_REG_KBCSR 0x1dc00  
#define HD64465_KBCSR_KBCIE 0x8000  
#define HD64465_KBCSR_KBCOE 0x4000  
#define HD64465_KBCSR_KBDOE 0x2000  
#define HD64465_KBCSR_KBCD 0x1000  
#define HD64465_KBCSR_KBDD 0x0800  
#define HD64465_KBCSR_KBCS 0x0400  
#define HD64465_KBCSR_KBDS 0x0200  
#define HD64465_KBCSR_KBDP 0x0100  
#define HD64465_KBCSR_KBD_MASK 0x00ff  
#define HD64465_REG_KBISR 0x1dc04  
#define HD64465_KBISR_KBRDF 0x0001  
#define HD64465_REG_MSCSR 0x1dc10  
#define HD64465_REG_MSISR 0x1dc14  

#define CONFIG_HD64465_IOBASE 0xb0000000

#define CONFIG_HD64465_IRQ 5

#define _HD64465_IO_MASK 0xf8000000
#define is_hd64465_addr(addr)   ((addr & _HD64465_IO_MASK) == (CONFIG_HD64465_IOBASE & _HD64465_IO_MASK))

#define HD64465_IRQ_BASE OFFCHIP_IRQ_BASE
#define HD64465_IRQ_NUM 16
#define HD64465_IRQ_ADC (HD64465_IRQ_BASE+0)
#define HD64465_IRQ_USB (HD64465_IRQ_BASE+1)
#define HD64465_IRQ_SCDI (HD64465_IRQ_BASE+2)
#define HD64465_IRQ_PARALLEL (HD64465_IRQ_BASE+3)

#define HD64465_IRQ_UART (HD64465_IRQ_BASE+5)
#define HD64465_IRQ_IRDA (HD64465_IRQ_BASE+6)
#define HD64465_IRQ_PS2MOUSE (HD64465_IRQ_BASE+7)
#define HD64465_IRQ_KBC (HD64465_IRQ_BASE+8)
#define HD64465_IRQ_TIMER1 (HD64465_IRQ_BASE+9)
#define HD64465_IRQ_TIMER0 (HD64465_IRQ_BASE+10)
#define HD64465_IRQ_GPIO (HD64465_IRQ_BASE+11)
#define HD64465_IRQ_AFE (HD64465_IRQ_BASE+12)
#define HD64465_IRQ_PCMCIA1 (HD64465_IRQ_BASE+13)
#define HD64465_IRQ_PCMCIA0 (HD64465_IRQ_BASE+14)
#define HD64465_IRQ_PS2KBD (HD64465_IRQ_BASE+15)

#define HD64465_PCC_WINDOW 0x01000000

#define HD64465_PCC0_BASE 0xb8000000  
#define HD64465_PCC0_ATTR (HD64465_PCC0_BASE)
#define HD64465_PCC0_COMM (HD64465_PCC0_BASE+HD64465_PCC_WINDOW)
#define HD64465_PCC0_IO (HD64465_PCC0_BASE+2*HD64465_PCC_WINDOW)

#define HD64465_PCC1_BASE 0xb4000000  
#define HD64465_PCC1_ATTR (HD64465_PCC1_BASE)
#define HD64465_PCC1_COMM (HD64465_PCC1_BASE+HD64465_PCC_WINDOW)
#define HD64465_PCC1_IO (HD64465_PCC1_BASE+2*HD64465_PCC_WINDOW)

#define HD64465_USB_BASE (CONFIG_HD64465_IOBASE+0xb000)
#define HD64465_USB_LEN 0x1000

#define HD64465_SRAM_BASE (CONFIG_HD64465_IOBASE+0x9000)
#define HD64465_SRAM_LEN 0x1000

#endif
