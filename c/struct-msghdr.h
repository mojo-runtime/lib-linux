#pragma once

#include "struct-iovec.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

struct msghdr
{
    void*
    msg_name;

    int
    msg_namelen;

    struct iovec*
    msg_iov;

    size_t
    msg_iovlen;

    void*
    msg_control;

    size_t
    msg_controllen;

    unsigned
    msg_flags;
};

#pragma clang diagnostic pop
