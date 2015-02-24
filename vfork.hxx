#ifndef linux_vfork_hxx_
#define linux_vfork_hxx_

#include "c/SYS_vfork.h"

#include "linux/fork.hxx"

namespace linux {

static inline
auto
vfork() noexcept
{
    return decltype(fork())(__call0(SYS_vfork)); // Same Result
}

} // namespace linux

#endif
