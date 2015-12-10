#pragma once

#include "Result.hxx"

#define EACCES 13
#define EBADF 9
#define EBUSY 16
#define EFAULT 14
#define EINVAL 22

#if defined(__x86_64__)
#  define ARCH_SET_FS 0x1002
#  define ARCH_GET_FS 0x1003
#  define __NR_prctl 158
#else
#  error
#endif

namespace linux {

template <typename Success, typename Argument>
static inline
auto
prctl(int option, Argument argument) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(BADF),
        _E(BUSY),
        _E(FAULT),
        _E(INVAL),
    };

    Result<Success, Error>
    result;

#if defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_prctl),
                    "D" (option),
                    "S" (argument)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
