#pragma once

#include "Result.hxx"

#define EACCES 13
#define EBUSY 16
#define EFAULT 14
#define EIO 5
#define EISDIR 21
// ELOOP
// ENAMETOOLONG
#define ENOENT 2
#define ENOMEM 12
#define ENOTDIR 20
#define EPERM 1
#define EROFS 30

#if defined(__alpha__) || defined(__hppa__) || defined(__mips__) || defined(__sparc__)
#  error
#else
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  if defined(__arm__)
#    define __NR_unlink 10
#  elif defined(__x86_64__)
#    define __NR_unlink 87
#  else
#    error
#  endif
#endif

namespace linux {

static inline
auto
unlink(const char* path) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(BUSY),
        _E(FAULT),
        _E(IO),
        _E(ISDIR),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOMEM),
        _E(NOTDIR),
        _E(PERM),
        _E(ROFS),
    };

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = __NR_unlink;
    register auto r1 asm ("r1") = path;

    asm volatile ("swi 0x0"
                  : "=r" (r0)
                  : "r" (r0),
                    "r" (r1)
                  : "memory");

    result.__word = r0;

#elif defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (result.__word)
                  : "a" (__NR_unlink),
                    "D" (path)
                  : "rcx", "r11");

#else
#  error
#endif

    return result;
}

}
