#ifndef c_SIGHUP_h_
#define c_SIGHUP_h_

#include "_define/SIG.h"

#ifdef __linux__
_c_define_SIG(HUP, 1);
#else
#  error
#endif

#endif
