# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.
#
# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.


# auto-generated by gensyscalls.py, do not touch
syscall_src := 
syscall_src += arch-x86/syscalls/_exit.S
syscall_src += arch-x86/syscalls/_exit_thread.S
syscall_src += arch-x86/syscalls/__fork.S
syscall_src += arch-x86/syscalls/_waitpid.S
syscall_src += arch-x86/syscalls/__waitid.S
syscall_src += arch-x86/syscalls/__sys_clone.S
syscall_src += arch-x86/syscalls/execve.S
syscall_src += arch-x86/syscalls/__setuid.S
syscall_src += arch-x86/syscalls/getuid.S
syscall_src += arch-x86/syscalls/getgid.S
syscall_src += arch-x86/syscalls/geteuid.S
syscall_src += arch-x86/syscalls/getegid.S
syscall_src += arch-x86/syscalls/getresuid.S
syscall_src += arch-x86/syscalls/getresgid.S
syscall_src += arch-x86/syscalls/gettid.S
syscall_src += arch-x86/syscalls/getgroups.S
syscall_src += arch-x86/syscalls/getpgid.S
syscall_src += arch-x86/syscalls/getppid.S
syscall_src += arch-x86/syscalls/setsid.S
syscall_src += arch-x86/syscalls/setgid.S
syscall_src += arch-x86/syscalls/__setreuid.S
syscall_src += arch-x86/syscalls/__setresuid.S
syscall_src += arch-x86/syscalls/setresgid.S
syscall_src += arch-x86/syscalls/__brk.S
syscall_src += arch-x86/syscalls/kill.S
syscall_src += arch-x86/syscalls/tkill.S
syscall_src += arch-x86/syscalls/__ptrace.S
syscall_src += arch-x86/syscalls/__set_thread_area.S
syscall_src += arch-x86/syscalls/__getpriority.S
syscall_src += arch-x86/syscalls/setpriority.S
syscall_src += arch-x86/syscalls/setrlimit.S
syscall_src += arch-x86/syscalls/getrlimit.S
syscall_src += arch-x86/syscalls/getrusage.S
syscall_src += arch-x86/syscalls/setgroups.S
syscall_src += arch-x86/syscalls/setpgid.S
syscall_src += arch-x86/syscalls/setregid.S
syscall_src += arch-x86/syscalls/chroot.S
syscall_src += arch-x86/syscalls/prctl.S
syscall_src += arch-x86/syscalls/capget.S
syscall_src += arch-x86/syscalls/capset.S
syscall_src += arch-x86/syscalls/sigaltstack.S
syscall_src += arch-x86/syscalls/acct.S
syscall_src += arch-x86/syscalls/read.S
syscall_src += arch-x86/syscalls/write.S
syscall_src += arch-x86/syscalls/__pread64.S
syscall_src += arch-x86/syscalls/__pwrite64.S
syscall_src += arch-x86/syscalls/__open.S
syscall_src += arch-x86/syscalls/__openat.S
syscall_src += arch-x86/syscalls/close.S
syscall_src += arch-x86/syscalls/lseek.S
syscall_src += arch-x86/syscalls/__llseek.S
syscall_src += arch-x86/syscalls/getpid.S
syscall_src += arch-x86/syscalls/__mmap2.S
syscall_src += arch-x86/syscalls/munmap.S
syscall_src += arch-x86/syscalls/mremap.S
syscall_src += arch-x86/syscalls/msync.S
syscall_src += arch-x86/syscalls/mprotect.S
syscall_src += arch-x86/syscalls/madvise.S
syscall_src += arch-x86/syscalls/mlock.S
syscall_src += arch-x86/syscalls/munlock.S
syscall_src += arch-x86/syscalls/mincore.S
syscall_src += arch-x86/syscalls/__ioctl.S
syscall_src += arch-x86/syscalls/readv.S
syscall_src += arch-x86/syscalls/writev.S
syscall_src += arch-x86/syscalls/__fcntl.S
syscall_src += arch-x86/syscalls/flock.S
syscall_src += arch-x86/syscalls/fchmod.S
syscall_src += arch-x86/syscalls/dup.S
syscall_src += arch-x86/syscalls/pipe.S
syscall_src += arch-x86/syscalls/pipe2.S
syscall_src += arch-x86/syscalls/dup2.S
syscall_src += arch-x86/syscalls/select.S
syscall_src += arch-x86/syscalls/ftruncate.S
syscall_src += arch-x86/syscalls/getdents.S
syscall_src += arch-x86/syscalls/fsync.S
syscall_src += arch-x86/syscalls/fdatasync.S
syscall_src += arch-x86/syscalls/fchown.S
syscall_src += arch-x86/syscalls/sync.S
syscall_src += arch-x86/syscalls/__fcntl64.S
syscall_src += arch-x86/syscalls/__fstatfs64.S
syscall_src += arch-x86/syscalls/sendfile.S
syscall_src += arch-x86/syscalls/fstatat.S
syscall_src += arch-x86/syscalls/mkdirat.S
syscall_src += arch-x86/syscalls/fchownat.S
syscall_src += arch-x86/syscalls/fchmodat.S
syscall_src += arch-x86/syscalls/renameat.S
syscall_src += arch-x86/syscalls/link.S
syscall_src += arch-x86/syscalls/unlink.S
syscall_src += arch-x86/syscalls/unlinkat.S
syscall_src += arch-x86/syscalls/chdir.S
syscall_src += arch-x86/syscalls/mknod.S
syscall_src += arch-x86/syscalls/chmod.S
syscall_src += arch-x86/syscalls/chown.S
syscall_src += arch-x86/syscalls/lchown.S
syscall_src += arch-x86/syscalls/mount.S
syscall_src += arch-x86/syscalls/umount2.S
syscall_src += arch-x86/syscalls/fstat.S
syscall_src += arch-x86/syscalls/stat.S
syscall_src += arch-x86/syscalls/lstat.S
syscall_src += arch-x86/syscalls/mkdir.S
syscall_src += arch-x86/syscalls/readlink.S
syscall_src += arch-x86/syscalls/rmdir.S
syscall_src += arch-x86/syscalls/rename.S
syscall_src += arch-x86/syscalls/__getcwd.S
syscall_src += arch-x86/syscalls/access.S
syscall_src += arch-x86/syscalls/symlink.S
syscall_src += arch-x86/syscalls/fchdir.S
syscall_src += arch-x86/syscalls/truncate.S
syscall_src += arch-x86/syscalls/__statfs64.S
syscall_src += arch-x86/syscalls/pause.S
syscall_src += arch-x86/syscalls/gettimeofday.S
syscall_src += arch-x86/syscalls/settimeofday.S
syscall_src += arch-x86/syscalls/times.S
syscall_src += arch-x86/syscalls/nanosleep.S
syscall_src += arch-x86/syscalls/clock_gettime.S
syscall_src += arch-x86/syscalls/clock_settime.S
syscall_src += arch-x86/syscalls/clock_getres.S
syscall_src += arch-x86/syscalls/clock_nanosleep.S
syscall_src += arch-x86/syscalls/getitimer.S
syscall_src += arch-x86/syscalls/setitimer.S
syscall_src += arch-x86/syscalls/__timer_create.S
syscall_src += arch-x86/syscalls/__timer_settime.S
syscall_src += arch-x86/syscalls/__timer_gettime.S
syscall_src += arch-x86/syscalls/__timer_getoverrun.S
syscall_src += arch-x86/syscalls/__timer_delete.S
syscall_src += arch-x86/syscalls/utimes.S
syscall_src += arch-x86/syscalls/sigaction.S
syscall_src += arch-x86/syscalls/sigprocmask.S
syscall_src += arch-x86/syscalls/__sigsuspend.S
syscall_src += arch-x86/syscalls/__rt_sigaction.S
syscall_src += arch-x86/syscalls/__rt_sigprocmask.S
syscall_src += arch-x86/syscalls/__rt_sigtimedwait.S
syscall_src += arch-x86/syscalls/sigpending.S
syscall_src += arch-x86/syscalls/socket.S
syscall_src += arch-x86/syscalls/bind.S
syscall_src += arch-x86/syscalls/connect.S
syscall_src += arch-x86/syscalls/listen.S
syscall_src += arch-x86/syscalls/accept.S
syscall_src += arch-x86/syscalls/getsockname.S
syscall_src += arch-x86/syscalls/getpeername.S
syscall_src += arch-x86/syscalls/socketpair.S
syscall_src += arch-x86/syscalls/sendto.S
syscall_src += arch-x86/syscalls/recvfrom.S
syscall_src += arch-x86/syscalls/shutdown.S
syscall_src += arch-x86/syscalls/setsockopt.S
syscall_src += arch-x86/syscalls/getsockopt.S
syscall_src += arch-x86/syscalls/sendmsg.S
syscall_src += arch-x86/syscalls/recvmsg.S
syscall_src += arch-x86/syscalls/sched_setscheduler.S
syscall_src += arch-x86/syscalls/sched_getscheduler.S
syscall_src += arch-x86/syscalls/sched_yield.S
syscall_src += arch-x86/syscalls/sched_setparam.S
syscall_src += arch-x86/syscalls/sched_getparam.S
syscall_src += arch-x86/syscalls/sched_get_priority_max.S
syscall_src += arch-x86/syscalls/sched_get_priority_min.S
syscall_src += arch-x86/syscalls/sched_rr_get_interval.S
syscall_src += arch-x86/syscalls/ioprio_set.S
syscall_src += arch-x86/syscalls/ioprio_get.S
syscall_src += arch-x86/syscalls/uname.S
syscall_src += arch-x86/syscalls/__wait4.S
syscall_src += arch-x86/syscalls/umask.S
syscall_src += arch-x86/syscalls/__reboot.S
syscall_src += arch-x86/syscalls/__syslog.S
syscall_src += arch-x86/syscalls/init_module.S
syscall_src += arch-x86/syscalls/delete_module.S
syscall_src += arch-x86/syscalls/klogctl.S
syscall_src += arch-x86/syscalls/sysinfo.S
syscall_src += arch-x86/syscalls/futex.S
syscall_src += arch-x86/syscalls/epoll_create.S
syscall_src += arch-x86/syscalls/epoll_ctl.S
syscall_src += arch-x86/syscalls/epoll_wait.S
syscall_src += arch-x86/syscalls/inotify_init.S
syscall_src += arch-x86/syscalls/inotify_add_watch.S
syscall_src += arch-x86/syscalls/inotify_rm_watch.S
syscall_src += arch-x86/syscalls/poll.S
syscall_src += arch-x86/syscalls/eventfd.S
