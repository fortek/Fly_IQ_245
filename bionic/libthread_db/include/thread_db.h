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
 * Copyright 2006 The Android Open Source Project
 */

#ifndef _LIBTHREAD_DB__THREAD_DB_H
#define _LIBTHREAD_DB__THREAD_DB_H

#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <sys/types.h>

typedef void *psaddr_t;
typedef pid_t lwpid_t;

#define TD_THR_ANY_USER_FLAGS       0xffffffff
#define TD_THR_LOWEST_PRIORITY      -20
#define TD_SIGNO_MASK               NULL

/* td_err_e values */
enum {
    TD_OK,
    TD_ERR,
    TD_NOTHR,
    TD_NOSV,
    TD_NOLWP,
    TD_BADPH,
    TD_BADTH,
    TD_BADSH,
    TD_BADTA,
    TD_BADKEY,
    TD_NOMSG,
    TD_NOFPREGS,
    TD_NOLIBTHREAD,
    TD_NOEVENT,
    TD_NOCAPAB,
    TD_DBERR,
    TD_NOAPLIC,
    TD_NOTSD,
    TD_MALLOC,
    TD_PARTIALREG,
    TD_NOXREGS,
    TD_VERSION
};

/*
 * td_event_e values 
 * NOTE: There is a max of 32 events
 */
enum {
    TD_CREATE,
    TD_DEATH
};

/* td_thr_state_e values */
enum {
    TD_THR_ANY_STATE,
    TD_THR_UNKNOWN,
    TD_THR_SLEEP,
    TD_THR_ZOMBIE
};

typedef int32_t td_err_e;
typedef uint32_t td_event_e;
typedef uint32_t td_notify_e;
typedef uint32_t td_thr_state_e;
typedef pthread_t thread_t;

typedef struct
{
    pid_t pid;
    struct ps_prochandle *ph;
} td_thragent_t;

typedef struct
{
    pid_t pid;
    pid_t tid;
} td_thrhandle_t;

typedef struct
{
    td_event_e event;
    td_thrhandle_t const * th_p;
    union {
        void * data;
    } msg;
} td_event_msg_t;

typedef struct
{
    uint32_t events;
} td_thr_events_t;

typedef struct
{
    union {
        void * bptaddr;
    } u;
} td_notify_t;

typedef struct
{
    td_thr_state_e ti_state;
    thread_t ti_tid; // pthread's id for the thread
    int32_t ti_lid; // the kernel's id for the thread
} td_thrinfo_t;


#define td_event_emptyset(set) \
    (set)->events = 0

#define td_event_fillset(set) \
    (set)->events = 0xffffffff

#define td_event_addset(set, n) \
    (set)->events |= (1 << n)


typedef int td_thr_iter_f(td_thrhandle_t const *, void *);


struct ps_prochandle;

#ifdef __cplusplus
extern "C"{
#endif

extern td_err_e td_ta_new(struct ps_prochandle * proc_handle, td_thragent_t ** thread_agent);

extern td_err_e td_ta_delete(td_thragent_t * ta);

extern td_err_e td_ta_set_event(td_thragent_t const * agent, td_thr_events_t * event);

extern td_err_e td_ta_event_addr(td_thragent_t const * agent, td_event_e event, td_notify_t * notify);

extern td_err_e td_ta_clear_event(const td_thragent_t * ta_arg,
				  td_thr_events_t * event);

extern td_err_e td_ta_event_getmsg(td_thragent_t const * agent, td_event_msg_t * event);

extern td_err_e td_ta_map_lwp2thr(td_thragent_t const * agent, lwpid_t lwpid,
				  td_thrhandle_t *th);

extern td_err_e td_thr_get_info(td_thrhandle_t const * handle,
				td_thrinfo_t * info);

extern td_err_e td_thr_event_enable(td_thrhandle_t const * handle,
				    td_event_e event);

extern td_err_e td_ta_thr_iter(td_thragent_t const * agent, td_thr_iter_f * func, void * cookie,
                               td_thr_state_e state, int32_t prio, sigset_t * sigmask, uint32_t user_flags);

extern char const ** td_symbol_list(void);

extern td_err_e td_thr_tls_get_addr(const td_thrhandle_t * th,
				    psaddr_t map_address, size_t offset,
				    psaddr_t * address);

#ifdef __cplusplus
}
#endif

#endif
