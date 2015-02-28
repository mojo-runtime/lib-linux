#ifndef c_posix_getegid_h_
#define c_posix_getegid_h_

#include "compatibility/NOTHROW.h"

#include "SYS_getegid.h"
#include "gid_t.h"
#include "_system_call_0.h"
#include "_system_Result_ok.h"

NOTHROW
static
gid_t
getegid()
{
    return _system_Result_ok(gid_t, _system_call_0(SYS_getegid));
}

#endif
