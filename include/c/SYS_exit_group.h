// -*- C -*-

#pragma once

#if defined(__linux__)
#  if defined(__x86_64__)
#    define SYS_exit_group 231
#  else
#    error
#  endif
#else
#  error
#endif