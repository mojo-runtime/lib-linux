#pragma once

#include "c/struct-cmsghdr.h"
#include "c/struct-msghdr.h"
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
#    define __NR_recvmsg 297
#  elif defined(__x86_64__)
#    define __NR_recvmsg 47
#  else
#    error
#  endif
#endif

namespace linux {

static inline
auto
recvmsg(int fd, struct msghdr* buffer, int flags) noexcept
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

    register Word r0 asm ("r0") = __NR_recvmsg;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = buffer;
    register auto r3 asm ("r3") = flags;

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
                  : "a" (__NR_recvmsg),
                    "D" (fd),
                    "S" (buffer),
                    "d" (flags)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
