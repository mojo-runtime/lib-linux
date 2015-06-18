#pragma once

#include "sa_family_t.h"

struct sockaddr
{
    sa_family_t
    sa_family;

    char
    sa_data[14];
};
