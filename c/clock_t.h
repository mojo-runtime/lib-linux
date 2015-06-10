#pragma once

#if defined(__i386__)
typedef /* __kernel_long_t */ long long clock_t;
#else
typedef /* __kernel_long_t */ long clock_t;
#endif
