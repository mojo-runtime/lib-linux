#ifndef c_linux_gettid_h_
#define c_linux_gettid_h_

#include "attribute/nothrow.h"

#include "SYS_gettid.h"
#include "pid_t.h"
#include "_c_syscall0_cannot_fail.h"

attribute_nothrow
static
pid_t
gettid()
{
    return _c_syscall0_cannot_fail(SYS_gettid, pid_t);
}

#endif
