#pragma once

#include "c/off_t.h"
#include "c/size_t.h"
#include "Result.hxx"

#define EACCES 13
// EAGAIN
#define EBADF 9
#define EINVAL 22
#define ENFILE 23
#define ENODEV 19
#define ENOMEM 12
// EOVERFLOW
#define EPERM 1

#define MAP_ANONYMOUS 0x20
#define MAP_PRIVATE 0x2
#define MAP_SHARED 0x1

#define PROT_EXEC 0x4
#define PROT_NONE 0x0
#define PROT_READ 0x1
#define PROT_WRITE 0x2

#if defined(__arm__)
#  define EAGAIN 11
#  define EOVERFLOW 75
#  define __NR_mmap 90
#elif defined(__x86_64__)
#  define EAGAIN 11
#  define EOVERFLOW 75
#  define __NR_mmap 9
#else
#  error
#endif

namespace linux {

static inline
auto
mmap(void* address, size_t length, int protection, int flags, int fd, off_t offset) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(AGAIN),
        _E(BADF),
        _E(INVAL),
        _E(NFILE),
        _E(NODEV),
        _E(NOMEM),
        _E(OVERFLOW),
        _E(PERM),
        // ETXTBSY: MAP_DENYWRITE is ignored
    };

    Result<void*, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_mmap;
    register auto r1 asm ("r1") = address;
    register auto r2 asm ("r2") = length;
    register auto r3 asm ("r3") = protection;
    register auto r4 asm ("r4") = flags;
    register auto r5 asm ("r5") = fd;
    register auto r6 asm ("r6") = offset;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3),
                    "r" (r4),
                    "r" (r5),
                    "r" (r6)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    register auto r10 asm ("r10") = flags;
    register auto r8  asm ("r8")  = fd;
    register auto r9  asm ("r9")  = offset;

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_mmap),
                    "D" (address),
                    "S" (length),
                    "d" (protection),
                    "r" (r10),
                    "r" (r8),
                    "r" (r9)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
