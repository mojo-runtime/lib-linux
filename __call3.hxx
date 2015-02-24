#ifndef linux_call3_hxx_
#define linux_call3_hxx_

#include "linux/__Word.hxx"

namespace linux {

template <typename A1, typename A2, typename A3>
static inline
__Word
__call3(__Word number, A1 a1, A2 a2, A3 a3) noexcept
{
    __Word result;

#ifdef __x86_64__
    register A1 r1 asm ("rdi") = a1;
    register A2 r2 asm ("rsi") = a2;
    register A3 r3 asm ("rdx") = a3;

    asm volatile ("syscall"
                  : "=a" (result)
                  : "0" (number), "r" (r1), "r" (r2), "r" (r3)
                  : "rcx", "r11");
#else
#  error
#endif

    return result;
}

} // namespace linux

#endif
