#ifndef c_SYS_mkdir_h_
#define c_SYS_mkdir_h_

#include "_define/SYS_.h"

#if defined(__linux__) && defined(__x86_64__)
_c_define_SYS_(mkdir, 83);
#else
#  error
#endif

#endif
