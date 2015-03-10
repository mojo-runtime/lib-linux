#ifndef unix_geteuid_h_
#define unix_geteuid_h_

#include "c/SYS_geteuid.h"
#include "c/uid_t.h"
#include "c/_c_nothrow.h"

#include "_syscall_0.h"
#include "_syscall_Result_ok.h"

_c_nothrow
static
uid_t
geteuid()
{
    return _syscall_Result_ok(uid_t, _syscall_0(SYS_geteuid));
}

#endif
