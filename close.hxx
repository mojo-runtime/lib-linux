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
#if defined(_ENABLE_SIGNAL_HANDLERS)
        _E(INTR),
#endif
        _E(IO),
    };

    Result<void, Error>
    result;

#if defined(__arm__)
#  define __NR_close 6

    register Word r0 asm ("r0") = __NR_close;
    register auto r1 asm ("r1") = fd;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)
#  define __NR_close 3

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_close),
                    "D" (fd)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
