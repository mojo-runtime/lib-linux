#pragma once

#if defined(__arm__) || defined(__x86_64__) // generic
typedef int clockid_t;
#else
#  error
#endif
