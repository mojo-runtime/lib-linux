#pragma once

#include "c/pid_t.h"
#include "Result.hxx"

#define EAGAIN 11
#define ENOMEM 12
// ENOSYS

#if defined(__arm__)
#  define ENOSYS 38
#elif defined(__x86_64__)
#  define ENOSYS 38
#else
#  error
#endif

namespace linux {

static inline
auto
fork() noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(NOMEM),
        _E(NOSYS),
    };

    Result<pid_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = 2;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (57)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
