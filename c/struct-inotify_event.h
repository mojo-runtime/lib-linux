#pragma once

#include <c/uint32_t.h>
#include <feature/__has_flexible_array.h>

struct inotify_event
{
    int
    wd;

    uint32_t
    mask;

    uint32_t
    cookie;

    uint32_t
    len;

#if __has_flexible_array
    char
    name[];
#else
#  error
#endif
};
