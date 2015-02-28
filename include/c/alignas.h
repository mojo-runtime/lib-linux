#ifndef alignas

#if !defined(__cplusplus)
#  include "feature/has_c_alignas.h"
#  if has_c_alignas
#    define alignas _Alignas
#  else
#    error
#  endif
#else
#  include "feature/has_cxx_alignas.h"
#  if !has_cxx_alignas
#    error
#  endif
#endif

#endif