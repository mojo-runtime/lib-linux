#pragma once

#include "Result.hxx"

#define EINVAL 22
#define EMFILE 24
#define ENFILE 23
#define ENOMEM 12

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define EPOLL_CLOEXEC 0x80000 // O_CLOEXEC
#  if defined(__arm__)
#    define __NR_epoll_create1 357
#  elif defined(__x86_64__)
#    define __NR_epoll_create1 291
#  else
#    error
#  endif
#endif

namespace linux {

static inline
auto
epoll_create1(int flags) noexcept
{
    enum Error
    {
        _E(INVAL),
        _E(MFILE),
        _E(NFILE),
        _E(NOMEM),
    };

    Result<int, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_epoll_create1;
    register auto r1 asm ("r1") = flags;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_epoll_create1),
                    "D" (flags)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
