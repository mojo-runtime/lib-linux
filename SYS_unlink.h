#ifndef c_SYS_unlink_h_
#define c_SYS_unlink_h_

#include "_define/SYS_.h"

#if defined(__linux__) && defined(__x86_64__)
_c_define_SYS_(unlink, 87);
#else
#  error
#endif

#endif
