#pragma once

#include <c/size_t.h>
#include "Result.hxx"

// EAGAIN
#define EBADF 9
// EDESTADDRREQ
// EDQUOT
#define EFAULT 14
#define EFBIG 27
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define ENOSPC 28
#define EPIPE 32

#if defined(__arm__)
#  define EAGAIN 11
#  define EDQUOT 122
#  define EDESTADDRREQ 89
#elif defined(__x86_64__)
#  define EAGAIN 11
#  define EDESTADDRREQ 89
#  define EDQUOT 122
#else
#  error
#endif

namespace linux {

static inline
auto
write(int fd, const void* buffer, size_t length) noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(BADF),
        _E(DESTADDRREQ),
        _E(DQUOT),
        _E(FAULT),
        _E(FBIG),
        _E(INTR),
        _E(INVAL),
        _E(IO),
        _E(NOSPC),
        _E(PIPE),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = 4;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = buffer;
    register auto r3 asm ("r3") = length;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (1),
                    "D" (fd),
                    "S" (buffer),
                    "d" (length)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
