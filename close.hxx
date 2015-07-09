#pragma once

#include "Result.hxx"

#define EBADF 9
#define EINTR 4
#define EIO 5

namespace linux {

static inline
auto
close(int fd) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(INTR),
        _E(IO),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = 6;
    register auto r1 asm ("r1") = fd;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (3),
                    "D" (fd)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
