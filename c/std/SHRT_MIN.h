#ifndef SHRT_MIN

#include "../__SIGNED_INTEGER_REPRESENTATION.h"

#if __SIGNED_INTEGER_REPRESENTATION == __SIGNED_INTEGER_REPRESENTATION_TWOS_COMPLEMENT
#  include "SHRT_MAX.h"
#  define SHRT_MIN (-INT_MAX - 1)
#else
#  error
#endif

#endif
