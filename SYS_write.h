#ifndef c_SYS_write_h_
#define c_SYS_write_h_

#include "_define/SYS_.h"

#if defined(__linux__) && defined(__x86_64__)
_c_define_SYS_(write, 1);
#else
#  error
#endif

#endif
