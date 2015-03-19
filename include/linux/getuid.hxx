#pragma once

#include <uid_t>

#include "__call.hxx"

namespace linux {

static inline
uid_t
getuid() noexcept
{
#if defined(__x86_64__)
    return __call<102>().ok<uid_t>();
#else
#  error
#endif
}

}