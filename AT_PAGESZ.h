#ifndef c_AT_PAGESZ_h_
#define c_AT_PAGESZ_h_

#include "_define/AT_.h"

#if defined(__linux__)
_c_define_AT_(PAGESZ, 6);
#else
#  error
#endif

#endif
