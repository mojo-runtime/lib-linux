#ifndef c_SIGSEGV_h_
#define c_SIGSEGV_h_

#include "_define/SIG.h"

#ifdef __linux__
_c_define_SIG(SEGV, 11);
#else
#  error
#endif

#endif
