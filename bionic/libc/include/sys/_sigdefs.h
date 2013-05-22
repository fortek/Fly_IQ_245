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

/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * this header is used to define signal constants and names;
 * it might be included several times
 */

#ifndef __BIONIC_SIGDEF
#error __BIONIC_SIGDEF not defined
#endif

__BIONIC_SIGDEF(HUP,1,"Hangup")
__BIONIC_SIGDEF(INT,2,"Interrupt")
__BIONIC_SIGDEF(QUIT,3,"Quit")
__BIONIC_SIGDEF(ILL,4,"Illegal instruction")
__BIONIC_SIGDEF(TRAP,5,"Trap")
__BIONIC_SIGDEF(ABRT,6,"Aborted")
__BIONIC_SIGDEF(BUS,7,"Bus error")
__BIONIC_SIGDEF(FPE,8,"Floating point exception")
__BIONIC_SIGDEF(KILL,9,"Killed")
__BIONIC_SIGDEF(USR1,10,"User signal 1")
__BIONIC_SIGDEF(SEGV,11,"Segmentation fault")
__BIONIC_SIGDEF(USR2,12,"User signal 2")
__BIONIC_SIGDEF(PIPE,13,"Broken pipe")
__BIONIC_SIGDEF(ALRM,14,"Alarm clock")
__BIONIC_SIGDEF(TERM,15,"Terminated")
__BIONIC_SIGDEF(STKFLT,16,"Stack fault")
__BIONIC_SIGDEF(CHLD,17,"Child exited")
__BIONIC_SIGDEF(CONT,18,"Continue")
__BIONIC_SIGDEF(STOP,19,"Stopped (signal)")
__BIONIC_SIGDEF(TSTP,20,"Stopped")
__BIONIC_SIGDEF(TTIN,21,"Stopped (tty input)")
__BIONIC_SIGDEF(TTOU,22,"Stopper (tty output)")
__BIONIC_SIGDEF(URG,23,"Urgent I/O condition")
__BIONIC_SIGDEF(XCPU,24,"CPU time limit exceeded")
__BIONIC_SIGDEF(XFSZ,25,"File size limit exceeded")
__BIONIC_SIGDEF(VTALRM,26,"Virtual timer expired")
__BIONIC_SIGDEF(PROF,27,"Profiling timer expired")
__BIONIC_SIGDEF(WINCH,28,"Window size changed")
__BIONIC_SIGDEF(IO,29,"I/O possible")
__BIONIC_SIGDEF(PWR,30,"Power failure")
__BIONIC_SIGDEF(SYS,31,"Bad system call")

#undef __BIONIC_SIGDEF
