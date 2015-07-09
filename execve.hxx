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
#  define ELIBBAD 80
#  define ELOOP 40
#  define ENAMETOOLONG 36
#elif defined(__x86_64__)
#  define ELIBBAD 80
#  define ELOOP 40
#  define ENAMETOOLONG 36
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

    Result<void, Error>
    result;

#if defined(__arm__)

    register Word r0 asm ("r0") = 11;
    register auto r1 asm ("r1") = filename;
    register auto r2 asm ("r2") = argv;
    register auto r3 asm ("r3") = envp;

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
                  : "a" (59),
                    "D" (filename),
                    "S" (argv),
                    "d" (envp)
                  : "rcx", "r11");

#else
#  error
#endif

    return result.error();
}

}
