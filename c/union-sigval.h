#pragma once

union sigval
{
    // LINUX/include/uapi/asm-generic/siginfo.h

    int
    sival_int;

    void*
    sival_ptr;
};
