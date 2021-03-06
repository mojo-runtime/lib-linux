#pragma once

#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define EINVAL 22
#define ENOTTY 25

#if defined(__arm__)
#  define __NR_ioctl 54
#elif defined(__x86_64__)
#  define __NR_ioctl 16
#else
#  error
#endif

namespace linux {

// The type of `request` varies from man page to man page.
// See: https://sourceware.org/bugzilla/show_bug.cgi?id=14362

template <typename Argument>
static inline
auto
ioctl(int fd, int request, Argument argument) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(INVAL),
        _E(NOTTY),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_ioctl;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = request;
    register auto r3 asm ("r3") = argument;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3)
                  : "memory");

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_ioctl),
                    "D" (fd),
                    "S" (request),
                    "d" (argument)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
