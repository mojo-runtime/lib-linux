#pragma once

#include "c/pid_t.h"
#include "Result.hxx"

#define EAGAIN 11
#define ENOMEM 12
// ENOSYS

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define ENOSYS 38
#  define __NR_fork 2
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define ENOSYS 38
#  define __NR_fork 57
#else
#  error
#endif

namespace linux {

static inline
auto
fork() noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(NOMEM),
        _E(NOSYS),
    };

    return Result<pid_t, Error>(
        _call<__NR_fork>()
    );
}

}
