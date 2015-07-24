#pragma once

#include "c/socklen_t.h"
#include "Result.hxx"

#define EACCES 13
// EADDRINUSE
// EADDRNOTAVAIL      AF_UNIX
#define EBADF 9
#define EFAULT 14 //  AF_UNIX
#define EINVAL 22
// ELOOP              AF_UNIX
// ENAMETOOLONG       AF_UNIX
#define ENOENT 2   // AF_UNIX
#define ENOMEM 12  // AF_UNIX
#define ENOTDIR 20 // AF_UNIX
// ENOTSOCK
#define EROFS 30   // AF_UNIX

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define EADDRINUSE 98
#  define EADDRNOTAVAIL 99
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define ENOTSOCK 88
#  if defined(__arm__)
#    define __NR_bind 282
#  elif defined(__x86_64__)
#    define __NR_bind 49
#  else
#    error
#  endif
#endif

namespace linux {

// Template this, as…
// "The only purpose of this structure (sockaddr) is to cast the structure pointer
//  passed in `addr` in order to avoid compiler warnings."

template <typename Address>
static inline
auto
bind(int fd, const Address* address, socklen_t length) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(ADDRINUSE),
        _E(ADDRNOTAVAIL),
        _E(BADF),
        _E(FAULT),
        _E(INVAL),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOMEM),
        _E(NOTDIR),
        _E(NOTSOCK),
        _E(ROFS),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_bind;
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
                  : "a" (__NR_bind),
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
