#pragma once

#include <c/size_t.h>
#include "Result.hxx"

// EAGAIN
#define EBADF 9
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define EISDIR 21

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define EAGAIN 11
#  define __NR_read 3
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
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
        _E(INTR),
        _E(INVAL),
        _E(IO),
        _E(ISDIR),
    };

    return Result<size_t, Error>(
        _call<__NR_read>(fd, buffer, length)
    );
}

}
