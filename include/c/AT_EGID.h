#pragma once

#if defined(__linux__) || defined(__FreeBSD__)
#  define AT_EGID 14
#else
#  error
#endif
