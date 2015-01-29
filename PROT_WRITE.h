#ifndef _c__PROT_WRITE_h
#define _c__PROT_WRITE_h

#include "c/_ProtectionFlags.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const _ProtectionFlags
PROT_WRITE =
#ifdef __linux__
 2
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
