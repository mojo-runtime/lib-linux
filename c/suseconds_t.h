#pragma once

#if defined(__i386__)
typedef /* __kernel_long_t */ long long suseconds_t;
#else
typedef /* __kernel_long_t */ long suseconds_t;
#endif
