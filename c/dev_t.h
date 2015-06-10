#pragma once

#if defined(__arm__)
#  if defined(__ARMEB__)
typedef unsigned short dev_t;
#  else
typedef unsigned long dev_t;
#  endif
#elif defined(__x86_64__)
typedef unsigned long dev_t;
#else
#  error
#endif
