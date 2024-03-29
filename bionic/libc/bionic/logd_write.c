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
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

#include "logd.h"

/* should match system/core/include/cutils/logger.h */
#define LOGGER_LOG_MAIN     "log/main"
#define LOGGER_LOG_RADIO    "log/radio"
#define LOGGER_LOG_EVENTS   "log/events"
#define LOGGER_LOG_SYSTEM   "log/system"

#include <pthread.h>

#define LOG_BUF_SIZE    1024

typedef enum {
    LOG_ID_NONE = 0,
    LOG_ID_MAIN,
    LOG_ID_RADIO,
    LOG_ID_MAX
} log_id_t;

/* logger handles writing to object, pointed by log channel id */
typedef int (*logger_function_t)(log_id_t log_id, struct iovec *vec);

typedef struct {
    logger_function_t logger;
    int               fd;
    const char        *path;
} log_channel_t;

static int __write_to_log_init(log_id_t log_id, struct iovec *vec);
static int __write_to_log_null(log_id_t log_id, struct iovec *vec);

static pthread_mutex_t log_init_lock = PTHREAD_MUTEX_INITIALIZER;

static log_channel_t log_channels[LOG_ID_MAX] = {
    { __write_to_log_null, -1, NULL },
    { __write_to_log_init, -1, "/dev/"LOGGER_LOG_MAIN },
    { __write_to_log_init, -1, "/dev/"LOGGER_LOG_RADIO }
};

static int __write_to_log_null(log_id_t log_id, struct iovec *vec)
{
    /* 
     * ALTERED behaviour from previous version
     * always returns successful result
     */
    int    i = 0;
    size_t res = 0;

    for ( ; i < 3; ++i) {
        res += vec[i].iov_len;
    }

    return (int)res;
}

/*
 *  it's supposed, that log_id contains valid id always.
 *  this check must be performed in higher level functions
 */
static int __write_to_log_kernel(log_id_t log_id, struct iovec *vec)
{
    ssize_t ret;

    do {
        ret = writev(log_channels[log_id].fd, vec, 3);
    } while ((ret < 0) && (errno == EINTR));

    return ret;
}

static int __write_to_log_init(log_id_t log_id, struct iovec *vec)
{
    if ((LOG_ID_NONE < log_id) && (log_id < LOG_ID_MAX)) {
        pthread_mutex_lock(&log_init_lock);

        int fd = open(log_channels[log_id].path, O_WRONLY);

        log_channels[log_id].logger =
            (fd < 0) ? __write_to_log_null : __write_to_log_kernel;
        log_channels[log_id].fd = fd;

        log_channels[log_id].fd = fd;

        pthread_mutex_unlock(&log_init_lock);

        return log_channels[log_id].logger(log_id, vec);
    }

    /* log_id is invalid */
    return -1;
}

static int __android_log_write(int prio, const char *tag, const char *msg)
{
    struct iovec vec[3];
    log_id_t log_id = LOG_ID_MAIN;

    if (tag == NULL)
        tag = "";

    if (!strcmp(tag, "HTC_RIL"))
        log_id = LOG_ID_RADIO;

    vec[0].iov_base   = (unsigned char *) &prio;
    vec[0].iov_len    = 1;
    vec[1].iov_base   = (void *) tag;
    vec[1].iov_len    = strlen(tag) + 1;
    vec[2].iov_base   = (void *) msg;
    vec[2].iov_len    = strlen(msg) + 1;

    return log_channels[log_id].logger(log_id, vec);
}


int __libc_android_log_vprint(int prio, const char *tag, const char *fmt,
                              va_list ap)
{
    char buf[LOG_BUF_SIZE];

    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);

    return __android_log_write(prio, tag, buf);
}

int __libc_android_log_print(int prio, const char *tag, const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    return __android_log_write(prio, tag, buf);
}

int __libc_android_log_assert(const char *cond, const char *tag,
			      const char *fmt, ...)
{
    va_list ap;
    char buf[LOG_BUF_SIZE];    

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);

    __android_log_write(ANDROID_LOG_FATAL, tag, buf);

    exit(1);

    return -1;
}
