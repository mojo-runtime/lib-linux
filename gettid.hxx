#ifndef linux_gettid_hxx_
#define linux_gettid_hxx_

#include "c/SYS_gettid.h"
#include "c/pid_t.h"
#include "linux/__call0.hxx"

namespace linux {

static inline
pid_t
gettid() noexcept
{
    return static_cast<pid_t>(__call0(SYS_gettid));
}

} // namespace linux

#endif
