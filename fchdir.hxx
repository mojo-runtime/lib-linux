#ifndef linux_fchdir_hxx_
#define linux_fchdir_hxx_

#include "c/EACCES.h"
#include "c/EBADF.h"
#include "c/SYS_fchdir.h"
#include "linux/__call1.hxx"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
fchdir(int fd) noexcept
{
    // TODO(?): "The general errors for `fchdir()` are listed below:

    enum Error
    {
        // Search permission was denied on the directory open on `fd`.
        EACCES_ = EACCES,

        // `fd` is not a valid file descriptor.
        EBADF_ = EBADF,

        // ENOTDIR, I imagine?
    };

    return Result<void, Error>(__call1(SYS_fchdir, fd));
}

} // namespace linux

#endif
