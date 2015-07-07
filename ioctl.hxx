#pragma once

#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define EINVAL 22
#define ENOTTY 25

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define __NR_ioctl 54
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define __NR_ioctl 16
#else
#  error
#endif

namespace linux {

// The type of `request` varies from man page to man page.
// See: https://sourceware.org/bugzilla/show_bug.cgi?id=14362

template <typename Arg>
static inline
auto
ioctl(int fd, int request, Arg arg) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(INVAL),
        _E(NOTTY),
    };

    return Result<void, Error>(
        _call<__NR_ioctl>(fd, request, arg)
    );
}

}
