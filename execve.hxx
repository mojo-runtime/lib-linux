#pragma once

#include "Result.hxx"

#define E2BIG 7
#define EACCES 13
#define EFAULT 14
#define EINVAL 22
#define EIO 5
#define EISDIR 21
// ELIBBAD
// ELOOP
#define EMFILE 24
// ENAMETOOLONG
#define ENFILE 23
#define ENOENT 2
#define ENOEXEC 8
#define ENOMEM 12
#define ENOTDIR 20
#define EPERM 1
#define ETXTBSY 26

#if defined(__arm__)
#  include "_arm/_call.hxx"
#  define ELIBBAD 80
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define __NR_execve 11
#elif defined(__x86_64__)
#  include "_x86_64/_call.hxx"
#  define ELIBBAD 80
#  define ELOOP 40
#  define ENAMETOOLONG 36
#  define __NR_execve 59
#else
#  error
#endif

namespace linux {

static inline
auto
execve(const char* filename, char* const argv[], char* const envp[]) noexcept
{
    enum Error
    {
        _E(2BIG),
        _E(ACCES),
        _E(FAULT),
        _E(INVAL),
        _E(IO),
        _E(ISDIR),
        _E(LIBBAD),
        _E(LOOP),
        _E(MFILE),
        _E(NAMETOOLONG),
        _E(NFILE),
        _E(NOENT),
        _E(NOEXEC),
        _E(NOMEM),
        _E(NOTDIR),
        _E(PERM),
        _E(TXTBSY),
    };

    return Result<void, Error>(
        _call<__NR_execve>(filename, argv, envp)
    ).error();
}

}
