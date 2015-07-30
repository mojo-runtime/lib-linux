#pragma once

#include "c/size_t.h"
#include "Result.hxx"

// EAGAIN
#define EBADF 9
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define EISDIR 21

#if defined(__arm__)
#  define EAGAIN 11
#  define __NR_read 3
#elif defined(__x86_64__)
#  define EAGAIN 11
#  define __NR_read 0
#else
#  error
#endif

namespace linux {

static inline
auto
read(int fd, void* buffer, size_t length) noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(BADF),
        _E(FAULT),
        _E(INTR), // In the absence of signal handlers, iff an inotify file descriptor
        _E(INVAL),
        _E(IO),
        _E(ISDIR),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_read;
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
                  : "a" (__NR_read),
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
