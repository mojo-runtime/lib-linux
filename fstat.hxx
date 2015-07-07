#pragma once

#include "c/struct-stat.h"
#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define ENOMEM 12
// EOVERFLOW

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define EOVERFLOW 75
#  define __NR_fstat 108
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define EOVERFLOW 75
#  define __NR_fstat 5
#else
#  error
#endif

namespace linux {

static inline
auto
fstat(int fd, struct stat* sb) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(NOMEM),
        _E(OVERFLOW),
    };

    return Result<void, Error>(
        _call<__NR_fstat>(fd, sb)
    );
}

}
