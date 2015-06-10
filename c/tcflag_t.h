#pragma once

#if defined(__sparc__) && !defined(__arch64__)
typedef unsigned long tcflag_t;
#else
typedef unsigned int tcflag_t;
#endif
