#ifndef c_CLD_STOPPED_h_
#define c_CLD_STOPPED_h_

#include "_c_CLD_.h"

#if defined(__linux__)
_c_CLD_(STOPPED, 5);
#else
#  error
#endif

#endif
