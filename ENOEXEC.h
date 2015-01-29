#ifndef _c__ENOEXEC_h
#define _c__ENOEXEC_h

#include "c/_ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _ErrorNumber
ENOEXEC =
#ifdef __linux__
 8
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
