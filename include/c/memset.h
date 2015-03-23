#pragma once

#include "size_t.h"

static inline
void*
memset(void* s, int c, size_t n)
{
#if defined(__has_builtin)
#  if __has_builtin(__builtin_memset)
    return __builtin_memset(s, c, n);
#  else
#    error
#  endif
#elif defined(__GNUC__)
    return __builtin_memset(s, c, n);
#else
#  error
#endif
}
