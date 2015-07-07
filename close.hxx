#pragma once

#include "Result.hxx"

#define EBADF 9
#define EINTR 4
#define EIO 5

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define __NR_close 6
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define __NR_close 3
#else
#  error
#endif

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

    return Result<void, Error>(
        _call<__NR_close>(fd)
    );
}

}
