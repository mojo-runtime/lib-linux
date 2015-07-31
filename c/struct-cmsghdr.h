#pragma once

#include "size_t.h"

struct cmsghdr
{
    size_t
    cmsg_len;

    int
    cmsg_level;

    int
    cmsg_type;
};
