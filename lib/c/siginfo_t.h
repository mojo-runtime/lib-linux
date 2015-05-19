#pragma once

#if defined(__linux__)
#  if defined(__x86_64__)
#    include "clock_t.h"
#    include "pid_t.h"
#    include "uid_t.h"
#    include "union-sigval.h"

typedef struct siginfo
{
    // Explicit padding for -Wpadded

    int
    si_signo;

    int
    si_errno;

    int
    si_code;

    char
    __padding[4];

    union
    {
        /*
         * int _pad[__SI_PAD_SIZE];
         *
         * LINUX/arch/x86/include/uapi/asm/siginfo.h:
         *   #define __ARCH_SI_PREAMBLE_SIZE (4 * sizeof(int))
         *                                 =  4 * 4
         *                                 =  16
         *
         * LINUX/include/uapi/asm-generic/siginfo.h:
         *   #define SI_MAX_SIZE 128
         *
         *   #ifndef SI_PAD_SIZE      (which is the case for x86_64)
         *   #define SI_PAD_SIZE ((SI_MAX_SIZE - __ARCH_SI_PREAMBLE_SIZE) / sizeof(int))
         *                       ((         128 - 16                    ) / 4
         *                                                            112 / 4
         *                                                                 28
         * x sizeof(int) = 112
         */
        char
        __padding[112];

        struct
        {
            pid_t
            _pid;

            uid_t
            _uid;
        }
        _kill;

        struct
        {
            int
            _tid;

            int
            _overrun;

            union sigval
            _sigval;
        }
        _timer;

        struct
        {
            pid_t
            _pid;

            uid_t
            _uid;

            union sigval
            _sigval;
        }
        _rt;

        struct
        {
            pid_t
            _pid;

            uid_t
            _uid;

            int
            _status;

            char
            __padding[4];

            clock_t
            _utime;

            clock_t
            _stime;
        }
        _sigchld;

        struct
        {
            void*
            _addr;

            short // int16_t
            _addr_lsb;

            char
            __padding[6];
        }
        _sigfault;

        struct
        {
            int
            _band;

            int
            _fd;

            char
            __padding[4];
        }
        _sigpoll;

        struct
        {
            void*
            _call_addr;

            int
            _syscall;

            unsigned int // uint32_t
            _arch;
        }
        _sigsys;
    }
    _sifields;
}
siginfo_t;

#  else
#    error
#  endif // __x86_64__

// TODO: is it possible to not use macros?
#  define si_pid       _sifields._kill._pid
#  define si_uid       _sifields._kill._uid
#  define si_timerid   _sifields._timer._tid
#  define si_overrun   _sifields._timer._overrun
#  define si_status    _sifields._sigchld._status
#  define si_utime     _sifields._sigchld._utime
#  define si_stime     _sifields._sigchld._stime
#  define si_value     _sifields._rt._sigval
#  define si_int       _sifields._rt._sigval.sival_int
#  define si_ptr       _sifields._rt._sigval.sival_ptr
#  define si_addr      _sifields._sigfault._addr
#  define si_addr_lsb  _sifields._sigfault._addr_lsb
#  define si_band      _sifields._sigpoll._band
#  define si_fd        _sifields._sigpoll._fd
#  define si_call_addr _sifields._sigsys._call_addr
#  define si_syscall   _sifields._sigsys._syscall
#  define si_arch      _sifields._sigsys._arch

#elif defined(__FreeBSD__)
#  include "pid_t.h"
#  include "uid_t.h"
#  include "union-sigval.h"

typedef struct {
    int
    si_code;

    pid_t
    si_pid;

    uid_t
    si_uid;

    int
    si_status;

    void*
    si_addr;

    union sigval
    si_value;

    union
    {
        struct
        {
            int
            _trapno;
        }
        _fault;

        struct
        {
            int
            _timerid;

            int
            _overrun;
        }
        _timer;

        struct
        {
            int
            _mqd;
        }
        _mesgq;

        struct
        {
            long
            _band;
        }
        _poll;

        struct
        {
            long
            __spare1__;

            int
            __spare2__[7];
        }
        __spare__;
    }
    _reason;
}
siginfo_t;

#  define si_trapno  _reason._fault._trapno
#  define si_timerid _reason._timer._timerid
#  define si_overrun _reason._timer._overrun
#  define si_mqd     _reason._mesgq._mqd
#  define si_band    _reason._poll._band
#else
#  error
#endif