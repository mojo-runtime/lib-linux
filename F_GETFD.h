#ifndef c_F_GETFD_h_
#define c_F_GETFD_h_

#include "_define/F_.h"

#ifdef __linux__
_c_define_F_(GETFD, 1);
#else
#  error
#endif

#endif
