#pragma once

#if defined(__linux__)
#  if defined(__arm__) || defined(__x86_64__) // generic
#    define EILSEQ 84
#  else
#    error
#  endif
#elif defined(__FreeBSD__)
#  define EILSEQ 86
#else
#  error
#endif
