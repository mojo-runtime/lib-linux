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
#  include "_arm/_call.hxx"
#  define __NR_getdents 141
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
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

    return Result<unsigned int, Error>(
        _call<__NR_getdents>(fd, dirp, count)
    );
}

}
