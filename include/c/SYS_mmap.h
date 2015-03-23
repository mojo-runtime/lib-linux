#pragma once

#if defined(__linux__)
#  if defined(__x86_64__)
#    define SYS_mmap 9
#  elif defined(__arm__)
#    define SYS_mmap 90
#  else
#    error
#  endif
#elif defined(__FreeBSD__)
#  define SYS_mmap 477
#else
#  error
#endif
