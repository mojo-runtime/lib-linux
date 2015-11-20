#pragma once

#include "c/struct-epoll_event.h"
#include "Result.hxx"

#define EBADF 9
#define EEXIST 17
#define EINVAL 22
#define ENOENT 2
#define ENOMEM 12
#define ENOSPC 28
#define EPERM 1

#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_DEL 2
#define EPOLL_CTL_MOD 3

#if defined(__arm__)
#  define __NR_epoll_ctl 251
#elif defined(__x86_64__)
#  define __NR_epoll_ctl 255
#else
#  error
#endif

namespace linux {

static inline
auto
epoll_ctl(int epfd, int op, int fd, struct epoll_event* event) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(EXIST),
        _E(INVAL),
        _E(NOENT),
        _E(NOMEM),
        _E(NOSPC),
        _E(PERM),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_epoll_ctl;
    register auto r1 asm ("r1") = epfd;
    register auto r2 asm ("r2") = op;
    register auto r3 asm ("r3") = fd;
    register auto r4 asm ("r4") = event;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3),
                    "r" (r4)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    register auto r10 asm ("r10") = event;

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_epoll_ctl),
                    "D" (epfd),
                    "S" (op),
                    "d" (fd),
                    "r" (r10)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
