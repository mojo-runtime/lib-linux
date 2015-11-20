#pragma once

#include "c/struct-epoll_event.h"
#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define EINTR 4
#define EINVAL 22

#if defined(__arm__)
#  define __NR_epoll_wait 252
#elif defined(__x86_64__)
#  define __NR_epoll_wait 232
#else
#  error
#endif

namespace linux {

static inline
auto
epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(INTR),
        _E(INVAL),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_epoll_wait;
    register auto r1 asm ("r1") = epfd;
    register auto r2 asm ("r2") = events;
    register auto r3 asm ("r3") = maxevents;
    register auto r4 asm ("r4") = timeout;

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
                  : "a" (__NR_epoll_wait),
                    "D" (epfd),
                    "S" (events),
                    "d" (maxevents),
                    "r" (timeout)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
