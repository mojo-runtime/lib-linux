#ifndef bool

#if !defined(__cplusplus)
#  include "feature/has_c_boolean_type.h"
#  if has_c_boolean_type
#    define bool _Bool
#  else
#    error
#  endif
#endif

#endif