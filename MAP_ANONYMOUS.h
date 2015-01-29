#ifndef _c__MAP_ANONYMOUS_h
#define _c__MAP_ANONYMOUS_h

#include "c/_MapFlags.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _MapFlags
MAP_ANONYMOUS =
#ifdef __linux__
#  ifdef __x86_64__
 0x20 // generic
#  else
#    error
#  endif
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
