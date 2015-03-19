#pragma once

#include <EACCES>
#include <EAGAIN>
#include <EBADF>
#include <EINVAL>
#include <ENFILE>
#include <ENODEV>
#include <ENOMEM>
#include <EOVERFLOW>
#include <EPERM>
#include <ETXTBSY>

namespace linux::mmap {

enum Error
{
#define _(name) _##name = name
    _(EACCES),
    _(EAGAIN),
    _(EBADF),
    _(EINVAL),
    _(ENFILE),
    _(ENODEV),
    _(ENOMEM),
    _(EOVERFLOW),
    _(EPERM),
    _(ETXTBSY),
#undef _
};

}