#pragma once

#include "size_t.h"

static inline
int
memcmp(const void* s1, const void* s2, size_t n)
{
#if defined(__has_builtin)
#  if __has_builtin(__builtin_memcmp)
    return __builtin_memcmp(s1, s2, n);
#  else
#    error
#  endif
#elif defined(__GNUC__)
    return __builtin_memcmp(s1, s2, n);
#else
#  error
#endif
}
