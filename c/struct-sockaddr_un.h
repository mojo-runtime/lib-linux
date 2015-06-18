#pragma once

#include "sa_family_t.h"

struct sockaddr_un
{
    sa_family_t
    sun_family;

    char
    sun_path[/* UNIX_PATH_MAX */108];
};
