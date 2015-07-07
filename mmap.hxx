#pragma once

#include <c/size_t.h>
#include "c/off_t.h"
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
#  include "_arm/_call.hxx"
#  define EAGAIN 11
#  define EOVERFLOW 75
#  define __NR_mmap 90
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define EAGAIN 11
#  define EOVERFLOW 75
#  define __NR_mmap 9
#else
#  error
#endif

namespace linux {

static inline
auto
mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset) noexcept
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

    return Result<void*, Error>(
        _call<__NR_mmap>(addr, length, prot, flags, fd, offset)
    );
}

}
