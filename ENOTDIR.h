#ifndef _c__ENOTDIR_h
#define _c__ENOTDIR_h

#include "c/_ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _ErrorNumber
ENOTDIR =
#ifdef __linux__
 20
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
