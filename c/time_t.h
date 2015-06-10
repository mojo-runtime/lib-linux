#pragma once

#if defined(__i386__)
typedef /* __kernel_long_t */ long long time_t;
#else
typedef /* __kernel_long_t */ long time_t;
#endif
