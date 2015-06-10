#pragma once

#if defined(__arm__)
typedef unsigned int nlink_t;
#elif defined(__x86_64__)
typedef unsigned long nlink_t;
#else
#  error
#endif
