#pragma once

#include "size_t.h"

struct iovec
{
    void*
    iov_base;

    size_t
    iov_len;
};
