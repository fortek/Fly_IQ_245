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
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include "logd.h"

void *__stack_chk_guard = 0;

/* Initialize the canary with a random value from /dev/urandom.
 * If that fails, use the "terminator canary". */
static void __attribute__ ((constructor))
__guard_setup(void)
{
    int fd;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd != -1) {
        ssize_t len = read(fd, &__stack_chk_guard,
                           sizeof(__stack_chk_guard));
        close(fd);
        if (len == sizeof(__stack_chk_guard))
            return;
    }

    /* If that failed, switch to 'terminator canary' */
    ((unsigned char *)&__stack_chk_guard)[0] = 0;
    ((unsigned char *)&__stack_chk_guard)[1] = 0;
    ((unsigned char *)&__stack_chk_guard)[2] = '\n';
    ((unsigned char *)&__stack_chk_guard)[3] = 255;
}

/* This is the crash handler.
 * Does a best effort at logging and calls _exit to terminate
 * the process immediately (without atexit handlers, etc.) */
void __stack_chk_fail(void)
{
    struct sigaction sa;
    sigset_t sigmask;
    static const char message[] = "stack corruption detected: aborted";
    char path[PATH_MAX];
    int count;

    /* Immediately block all (but SIGABRT) signal handlers from running code */
    sigfillset(&sigmask);
    sigdelset(&sigmask, SIGABRT);
    sigprocmask(SIG_BLOCK, &sigmask, NULL);

    /* Use /proc/self/exe link to obtain the program name for logging
     * purposes. If it's not available, we set it to "<unknown>" */
    if ((count = readlink("/proc/self/exe", path, sizeof(path) - 1)) == -1) {
        strlcpy(path, "<unknown>", sizeof(path));
    } else {
        path[count] = '\0';
    }

    /* Do a best effort at logging. This ends up calling writev(2) */
    __libc_android_log_print(ANDROID_LOG_FATAL, path, message);

    /* Make sure there is no default action for SIGABRT */
    bzero(&sa, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = SIG_DFL;
    sigaction(SIGABRT, &sa, NULL);

    /* Terminate the process and exit immediately */
    kill(getpid(), SIGABRT);

    _exit(127);
}
