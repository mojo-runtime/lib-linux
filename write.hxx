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
#  include "_arm/_call.hxx"
#  define EAGAIN 11
#  define EDQUOT 122
#  define EDESTADDRREQ 89
#  define __NR_write 4
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define EAGAIN 11
#  define EDESTADDRREQ 89
#  define EDQUOT 122
#  define __NR_write 1
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

    return Result<size_t, Error>(
        _call<__NR_write>(fd, buffer, length)
    );
}

}
