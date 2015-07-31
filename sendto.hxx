#pragma once

#include "c/size_t.h"
#include "Result.hxx"

#define EACCES 13
// EAGAIN
#define EBADF 9
// ECONNRESET
// EDESTADDRREQ
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
// EISCONN
// EMSGSIZE
// ENOBUFS
#define ENOMEM 12
// ENOTCONN
// EOPNOTSUPP
#define EPIPE 32

#define MSG_DONTWAIT 0x40
#define MSG_NOSIGNAL 0x4000

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define EAGAIN 11
#  define ECONNRESET 104
#  define EDESTADDRREQ 89
#  define EISCONN 106
#  define EMSGSIZE 90
#  define ENOBUFS 105
#  define ENOTCONN 107
#  define EOPNOTSUPP 95
#  if defined(__arm__)
#    define __NR_sendto 290
#  elif defined(__x86_64__)
#    define __NR_sendto 44
#  else
#    error
#  endif
#endif

namespace linux {

static inline
auto
sendto(int fd, const void* buffer, size_t length, int flags) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(AGAIN),
        _E(BADF),
        _E(CONNRESET),
        _E(DESTADDRREQ),
        _E(FAULT),
        _E(INTR),
        _E(INVAL),
        _E(ISCONN),
        _E(MSGSIZE),
        _E(NOBUFS),
        _E(NOMEM),
        _E(NOTCONN),
        _E(NOTSOCK),
        _E(OPNOTSUPP),
        _E(PIPE),
    };

    Result<size_t, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_sendto;
    register auto r1 asm ("r1") = fd;
    register auto r2 asm ("r2") = buffer;
    register auto r3 asm ("r3") = length;
    register auto r4 asm ("r4") = flags;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1),
                    "r" (r2),
                    "r" (r3),
                    "r" (r4)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    register auto r10 asm ("r10") = flags;

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_recvfrom),
                    "D" (fd),
                    "S" (buffer),
                    "d" (length),
                    "r" (r10)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
