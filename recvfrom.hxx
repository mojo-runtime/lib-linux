#pragma once

#include "c/size_t.h"
#include "c/socklen_t.h"
#include "Result.hxx"

// EAGAIN
#define EBADF 9
// ECONNREFUSED
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
#define ENOMEM 12
// ENOTCONN
// ENOTSOCK

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define EAGAIN 11
#  define ECONNREFUSED 111
#  define ENOTCONN 107
#  define ENOTSOCK 88
#  if defined(__arm__)
#    define __NR_recvfrom 292
#  elif defined(__x86_64__)
#    define __NR_recvfrom 45
#  else
#    error
#  endif
#endif

namespace linux {

static inline
auto
recvfrom(int fd, void* buffer, size_t length, int flags, void* address, socklen_t* addrlen) noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(BADF),
        _E(CONNREFUSED),
        _E(FAULT),
        _E(INTR),
        _E(INVAL),
        _E(NOMEM),
        _E(NOTCONN),
        _E(NOTSOCK),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_recvfrom;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = buffer;
    register auto r3 asm ("r3") = length;
    register auto r4 asm ("r4") = flags;
    register auto r5 asm ("r5") = address;
    register auto r6 asm ("r6") = addrlen;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3),
                    "r" (r4),
                    "r" (r5),
                    "r" (r6)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    register auto r10 asm ("r10") = flags;
    register auto r8  asm ("r8")  = address;
    register auto r9  asm ("r9")  = addrlen;

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_recvfrom),
                    "D" (fd),
                    "S" (buffer),
                    "d" (length),
                    "r" (r10),
                    "r" (r8),
                    "r" (r9)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
