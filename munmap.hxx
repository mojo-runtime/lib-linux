#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EINVAL 22

namespace linux {

static inline
auto
munmap(void* address, size_t length) noexcept
{
    enum Error
    {
        _E(INVAL),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = 91;
    register auto r1 asm ("r1") = address;
    register auto r2 asm ("r2") = length;

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
                  : "a" (11),
                    "D" (address),
                    "S" (length)
                  : "rcx", "r11");
#else
#  error
#endif

    return result;
}

}
