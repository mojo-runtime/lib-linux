#pragma once

#include <EBADF>
#include <EBUSY>
#include <EINTR>
#include <EINVAL>
#include <EMFILE>

namespace linux::dup3 {

enum Error
{
#define _(name) _##name = name
    _(EBADF),
    _(EBUSY),
    _(EINTR),
    _(EINVAL),
    _(EMFILE),
#undef _
};

}