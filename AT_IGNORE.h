#ifndef c_AT_IGNORE_h_
#define c_AT_IGNORE_h_

#include "_define/AT_.h"

#if defined(__linux__)
_c_define_AT_(IGNORE, 1);
#else
#  error
#endif

#endif
