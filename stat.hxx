#pragma once

#include "c/struct-stat.h"
#include "Result.hxx"

#define EACCES 13
#define EFAULT 14
// ELOOP
// ENAMETOOLONG
#define ENOENT 2
#define ENOMEM 12
#define ENOTDIR 20
// EOVERFLOW

#if defined(__arm__)
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define EOVERFLOW 75
#  define __NR_stat 106
#elif defined(__x86_64__)
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define EOVERFLOW 75
#  define __NR_stat 4
#else
#  error
#endif

namespace linux {

static inline
auto
stat(const char* pathname, struct stat* buf) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(FAULT),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOMEM),
        _E(NOTDIR),
        _E(OVERFLOW),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_stat;
    register auto r1 asm ("r1") = pathname;
    register auto r2 asm ("r2") = buf;

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
                  : "a" (__NR_stat),
                    "D" (pathname),
                    "S" (buf)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
