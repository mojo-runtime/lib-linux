#ifndef c_AT_BASE_PLATFORM_h_
#define c_AT_BASE_PLATFORM_h_

#include "_define/AT_.h"

#if defined(__linux__)
_c_define_AT_(BASE_PLATFORM, 24);
#else
#  error
#endif

#endif
