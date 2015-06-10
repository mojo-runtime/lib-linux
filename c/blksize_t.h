#pragma once

// Note that the kernel does not define this; we have to inspect `stat::st_blksize`.
#if defined(__arm__) || defined(__x86_64__)
typedef unsigned long blksize_t;
#else
#  error
#endif
