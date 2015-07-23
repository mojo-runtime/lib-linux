#pragma once

#include "c/struct-linux_dirent.h"
#include "Result.hxx"

#define DT_BLK 6
#define DT_CHR 2
#define DT_DIR 4
#define DT_FIFO 1
#define DT_LNK 10
#define DT_REG 8
#define DT_SOCK 12
#define DT_UNKNOWN 0
#define DT_WHT 14

#define EBADF 9
#define EFAULT 14
#define EINVAL 22
#define ENOENT 2
#define ENOTDIR 20

#if defined(__arm__)
#  define __NR_getdents 141
#elif defined(__x86_64__)
#  define __NR_getdents 78
#else
#  error
#endif

namespace linux {

static inline
auto
getdents(int fd, struct linux_dirent* dirp, unsigned int count) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(INVAL),
        _E(NOENT),
        _E(NOTDIR),
    };

    Result<unsigned int, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_getdents;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = dirp;
    register auto r3 asm ("r3") = count;

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
                  : "a" (__NR_getdents),
                    "D" (fd),
                    "S" (dirp),
                    "d" (count)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
