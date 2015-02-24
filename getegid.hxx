#ifndef linux_getegid_hxx_
#define linux_getegid_hxx_

#include "c/SYS_getegid.h"
#include "c/gid_t.h"
#include "linux/__call0.hxx"

namespace linux {

static inline
gid_t
getegid() noexcept
{
    return static_cast<gid_t>(__call0(SYS_getegid));
}

} // namespace linux

#endif
