#ifndef linux_clock_nanosleep_hxx_
#define linux_clock_nanosleep_hxx_

#include "c/EFAULT.h"
#include "c/EINTR.h"
#include "c/EINVAL.h"
#include "c/SYS_clock_nanosleep.h"
#include "c/clockid_t.h"
#include "c/struct-timespec.h"
#include "c/extension/x_syscall4.h"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
clock_nanosleep(clockid_t clock_id, int flags, const struct timespec* request, struct timespec* remain) noexcept
{
    enum Error
    {
        // `request` or `remain` specified an invalid address.
        EFAULT = EFAULT,

        // The sleep was interrupted by a signal handler.
        EINTR = EINTR,

        // The value in the `tv_nsec` field was not in the range 0 to 999999999.
        //
        // `tv_sec` was negative.
        //
        // `clock_id` was invalid.  (CLOCK_THREAD_CPUTIME_ID is not a permitted value for clock_id.)
        EINVAL = EINVAL,
    };

    return Result<void, Error>(x_syscall4(SYS_clock_nanosleep, clock_id, flags, request, remain));
}

} // namespace linux

#endif
