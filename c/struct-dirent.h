#pragma once

#if defined(_FILE_OFFSET_BITS)
#  error
#else
#  include "ino_t.h"
#  include "off_t.h"
#endif

struct dirent
{
#if defined(_FILE_OFFSET_BITS)
#  error
#else
    ino_t
    d_ino;

    off_t
    d_off;
#endif

    unsigned short
    d_reclen;

    unsigned char
    d_type;

    char
    d_name[256];
};
