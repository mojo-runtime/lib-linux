#ifndef _c__DT_FIFO_h
#define _c__DT_FIFO_h

#include "c/_DirentType.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _DirentType
DT_FIFO =
#ifdef __linux__
 1
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
