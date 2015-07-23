#pragma once

#include "c/struct-stat.h"
#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define ENOMEM 12
// EOVERFLOW

#if defined(__arm__)
#  define EOVERFLOW 75
#  define __NR_fstat 108
#elif defined(__x86_64__)
#  define EOVERFLOW 75
#  define __NR_fstat 5
#else
#  error
#endif

namespace linux {

static inline
auto
fstat(int fd, struct stat* buffer) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(NOMEM),
        _E(OVERFLOW),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_fstat;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = buffer;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_fstat),
                    "D" (fd),
                    "S" (buffer)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
