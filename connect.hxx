#pragma once

#include "c/socklen_t.h"
#include "Result.hxx"

#define EACCES 13
// EADDRINUSE
// EADDRNOTAVAIL
// EAFNOSUPPORT
// EAGAIN
#define EBADF 9
// ECONNREFUSED
#define EFAULT 14
// EINPROGRESS
#define EINTR 4
// ENETUNREACH
// ENOTSOCK
// EPROTOTYPE
// ETIMEDOUT
// "There may be other domain-specific error codes."…

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define EADDRINUSE 98
#  define EADDRNOTAVAIL 99
#  define EAFNOSUPPORT 97
#  define EAGAIN 11
#  define ECONNREFUSED 111
#  define EINPROGRESS 115
#  define ENETUNREACH 101
#  define ENOTSOCK 88
#  define EPROTOTYPE 91
#  define ETIMEDOUT 110
#  if defined(__arm__)
#    define __NR_connect 283
#  elif defined(__x86_64__)
#    define __NR_connect 42
#  else
#    error
#  endif
#endif

namespace linux {

template <typename Address>
static inline
auto
connect(int fd, const Address* address, socklen_t length) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(ADDRINUSE),
        _E(ADDRNOTAVAIL),
        _E(AFNOSUPPORT),
        _E(AGAIN),
        _E(BADF),
        _E(CONNREFUSED),
        _E(FAULT),
        _E(INPROGRESS),
        _E(INTR),
        _E(NETUNREACH),
        _E(NOTSOCK),
        _E(PROTOTYPE),
        _E(TIMEDOUT)
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_connect;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = address;
    register auto r3 asm ("r3") = length;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_connect),
                    "D" (fd),
                    "S" (address),
                    "d" (length)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
