#ifndef c_EPOLLWAKEUP_h_
#define c_EPOLLWAKEUP_h_

#include "_define/EPOLL.h"

#ifdef __linux__
_c_define_EPOLL(WAKEUP, 1 << 29);
#else
#  error
#endif

#endif
