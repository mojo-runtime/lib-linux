#pragma once

#if defined(__arm__) || defined(__x86_64__) // generic
typedef long off_t;
#else
#  error
#endif
