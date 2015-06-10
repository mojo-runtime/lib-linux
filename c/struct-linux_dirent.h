#pragma once

#if defined(__linux__)
#  include <feature/__has_flexible_array.h>

struct linux_dirent
{
    unsigned long
    d_ino;

    unsigned long
    d_off;

    unsigned short
    d_reclen;

#if __has_flexible_array
    char
    d_name[];
#else
#  error
#endif

    /*
    char
    pad;

    char
    d_type;
    */
};

#else
#  error
#endif
