#ifndef compiler_has_builtin_strcmp
#  ifdef __has_builtin
#    define compiler_has_builtin_strcmp __has_builtin(__builtin_strcmp)
#  elif defined __GNUC__
#    include "compiler/has/gcc/minor.h"
#    define compiler_has_builtin_strcmp has_gcc_minor(3, 2)
#  else
#    error todo
#  endif
#endif