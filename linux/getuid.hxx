#ifndef linux_getuid_hxx_
#define linux_getuid_hxx_

#include "SYS_getuid.h"
#include "uid_t.h"

#include "abi/_abi_syscall_0.h"

namespace linux {

static inline
uid_t
getuid() noexcept
{
    return static_cast<uid_t>(_abi_syscall_0(SYS_getuid));
}

} // namespace linux

#endif