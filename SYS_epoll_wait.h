#ifndef c_SYS_epoll_wait_h_
#define c_SYS_epoll_wait_h_

#include "_define/SYS_.h"

#if defined(__linux__) && defined(__x86_64__)
_c_define_SYS_(epoll_wait, 232);
#else
#  error
#endif

#endif
