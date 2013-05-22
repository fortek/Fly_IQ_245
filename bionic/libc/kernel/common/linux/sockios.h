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
#ifndef _LINUX_SOCKIOS_H
#define _LINUX_SOCKIOS_H

#include <asm/sockios.h>

#define SIOCINQ FIONREAD
#define SIOCOUTQ TIOCOUTQ

#define SIOCADDRT 0x890B  
#define SIOCDELRT 0x890C  
#define SIOCRTMSG 0x890D  

#define SIOCGIFNAME 0x8910  
#define SIOCSIFLINK 0x8911  
#define SIOCGIFCONF 0x8912  
#define SIOCGIFFLAGS 0x8913  
#define SIOCSIFFLAGS 0x8914  
#define SIOCGIFADDR 0x8915  
#define SIOCSIFADDR 0x8916  
#define SIOCGIFDSTADDR 0x8917  
#define SIOCSIFDSTADDR 0x8918  
#define SIOCGIFBRDADDR 0x8919  
#define SIOCSIFBRDADDR 0x891a  
#define SIOCGIFNETMASK 0x891b  
#define SIOCSIFNETMASK 0x891c  
#define SIOCGIFMETRIC 0x891d  
#define SIOCSIFMETRIC 0x891e  
#define SIOCGIFMEM 0x891f  
#define SIOCSIFMEM 0x8920  
#define SIOCGIFMTU 0x8921  
#define SIOCSIFMTU 0x8922  
#define SIOCSIFNAME 0x8923  
#define SIOCSIFHWADDR 0x8924  
#define SIOCGIFENCAP 0x8925  
#define SIOCSIFENCAP 0x8926 
#define SIOCGIFHWADDR 0x8927  
#define SIOCGIFSLAVE 0x8929  
#define SIOCSIFSLAVE 0x8930
#define SIOCADDMULTI 0x8931  
#define SIOCDELMULTI 0x8932
#define SIOCGIFINDEX 0x8933  
#define SIOGIFINDEX SIOCGIFINDEX  
#define SIOCSIFPFLAGS 0x8934  
#define SIOCGIFPFLAGS 0x8935
#define SIOCDIFADDR 0x8936  
#define SIOCSIFHWBROADCAST 0x8937  
#define SIOCGIFCOUNT 0x8938  
#define SIOCKILLADDR 0x8939  

#define SIOCGIFBR 0x8940  
#define SIOCSIFBR 0x8941  

#define SIOCGIFTXQLEN 0x8942  
#define SIOCSIFTXQLEN 0x8943  

#define SIOCETHTOOL 0x8946  

#define SIOCGMIIPHY 0x8947  
#define SIOCGMIIREG 0x8948  
#define SIOCSMIIREG 0x8949  

#define SIOCWANDEV 0x894A  

#define SIOCDARP 0x8953  
#define SIOCGARP 0x8954  
#define SIOCSARP 0x8955  

#define SIOCDRARP 0x8960  
#define SIOCGRARP 0x8961  
#define SIOCSRARP 0x8962  

#define SIOCGIFMAP 0x8970  
#define SIOCSIFMAP 0x8971  

#define SIOCADDDLCI 0x8980  
#define SIOCDELDLCI 0x8981  

#define SIOCGIFVLAN 0x8982  
#define SIOCSIFVLAN 0x8983  

#define SIOCBONDENSLAVE 0x8990  
#define SIOCBONDRELEASE 0x8991  
#define SIOCBONDSETHWADDR 0x8992  
#define SIOCBONDSLAVEINFOQUERY 0x8993  
#define SIOCBONDINFOQUERY 0x8994  
#define SIOCBONDCHANGEACTIVE 0x8995  

#define SIOCBRADDBR 0x89a0  
#define SIOCBRDELBR 0x89a1  
#define SIOCBRADDIF 0x89a2  
#define SIOCBRDELIF 0x89a3  

#define SIOCDEVPRIVATE 0x89F0  

#define SIOCPROTOPRIVATE 0x89E0  
#endif
