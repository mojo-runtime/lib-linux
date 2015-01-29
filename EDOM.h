#ifndef _c__EDOM_h
#define _c__EDOM_h

#include "c/_ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _ErrorNumber
EDOM =
#ifdef __linux__
 33
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
