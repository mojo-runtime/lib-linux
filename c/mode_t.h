#pragma once

#if defined(__arm__) || defined(__x86_64__) // generic
typedef unsigned int mode_t;
#else
#  error
#endif
