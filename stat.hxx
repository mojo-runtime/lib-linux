#pragma once

#include "c/struct-stat.h"
#include "Result.hxx"

#define EACCES 13
#define EFAULT 14
// ELOOP
// ENAMETOOLONG
#define ENOENT 2
#define ENOMEM 12
#define ENOTDIR 20
// EOVERFLOW

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define EOVERFLOW 75
#  define __NR_stat 106
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define EOVERFLOW 75
#  define __NR_stat 4
#else
#  error
#endif

namespace linux {

static inline
auto
stat(const char* pathname, struct stat* buf) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(FAULT),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOMEM),
        _E(NOTDIR),
        _E(OVERFLOW),
    };

    return Result<void, Error>(
        _call<__NR_stat>(pathname, buf)
    );
}

}
