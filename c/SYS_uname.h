#ifndef SYS_uname
#  ifdef __linux__
#    ifdef __x86_64__
#      define SYS_uname 63
#    else
#      error
#    endif
#  else
#    error
#  endif
#endif