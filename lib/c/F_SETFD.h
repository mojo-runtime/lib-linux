#pragma once

#if defined(__linux__) || defined(__FreeBSD__)
#  define F_SETFD 2
#else
#  error
#endif