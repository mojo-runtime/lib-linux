#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EINVAL 22

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define __NR_munmap 91
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define __NR_munmap 11
#else
#  error
#endif

namespace linux {

static inline
auto
munmap(void* address, size_t length) noexcept
{
    enum Error
    {
        _E(INVAL),
    };

    return Result<void, Error>(
        _call<__NR_munmap>(address, length)
    );
}

}
