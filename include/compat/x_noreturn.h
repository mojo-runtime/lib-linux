#ifndef x_noreturn

#if defined(__cplusplus)
#  include "has_attribute_noreturn.h"
#  if has_attribute_noreturn
#    define x_noreturn __attribute__((__noreturn__))
#  else
#    error
#  endif
#else
#  include "has_c_noreturn.h"
#  if has_c_noreturn
#    define x_noreturn _Noreturn
#  else
#    error
#  endif
#endif

#endif