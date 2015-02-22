#ifndef linux_ioctl_hxx_
#define linux_ioctl_hxx_

#include "c/EBADF.h"
#include "c/EFAULT.h"
#include "c/EINVAL.h"
#include "c/ENOTTY.h"
#include "c/SYS_ioctl.h"
#include "c/extension/x_syscall3.h"

#include "linux/Result.hxx"

namespace linux {

// The type of `request` varies from man page to man page.
// We'll use `int`, as will the constants in the C headers.
// See: https://sourceware.org/bugzilla/show_bug.cgi?id=14362

template <typename Arg>
static inline
auto
ioctl(int fd, int request, Arg arg) noexcept
{
    enum Error
    {
        // `d` is not a valid descriptor.
        EBADF = EBADF,

        // `argp` references an inaccessible memory area.
        EFAULT = EFAULT,

        // `request` or `argp` is not valid.
        EINVAL = EINVAL,

        // `d` is not associated with a character special device.
        //
        // The specified request does not apply to the kind of object
        // that the descriptor `d` references.
        ENOTTY = ENOTTY,
    };

    return Result<void, Error>(x_syscall3(SYS_ioctl, fd, request, arg));
}

} // namespace linux

#endif
