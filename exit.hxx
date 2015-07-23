#pragma once

#if defined(__arm__)
#  define __NR_exit 1
#elif defined(__x86_64__)
#  define __NR_exit 60
#else
#  error
#endif

namespace linux {

[[noreturn]]
static inline
void
exit(int status) noexcept
{
#if defined(__arm__)

    register int r0 asm ("r0") = __NR_exit;
    register int r1 asm ("r1") = statue;

    asm volatile ("swi 0x0"
                  :
                  : "r" (r0)
                    "r" (r1));

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  :
                  : "a" (__NR_exit),
                    "D" (status));

#else
#  error
#endif

    __builtin_unreachable();
}

}
