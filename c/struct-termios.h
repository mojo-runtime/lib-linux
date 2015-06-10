#pragma once

#include "cc_t.h"
#include "tcflag_t.h"

#if defined(__mips__)
#  define NCCS 23
#elif defined(__sparc__)
#  define NCCS 17
#else
#  define NCCS 19
#endif

struct termios
{
    tcflag_t
    c_iflag;

    tcflag_t
    c_oflag;

    tcflag_t
    c_cflag;

    tcflag_t
    c_lflag;

    cc_t
    c_line;

    cc_t
    c_cc[NCCS];
};
