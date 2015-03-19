#pragma once

#include <EACCES>
#include <EDQUOT>
#include <EEXIST>
#include <EFAULT>
#include <EINTR>
#include <EINVAL>
#include <EISDIR>
#include <ELOOP>
#include <EMFILE>
#include <ENAMETOOLONG>
#include <ENFILE>
#include <ENODEV>
#include <ENOENT>
#include <ENOMEM>
#include <ENOSPC>
#include <ENOTDIR>
#include <ENXIO>
#include <EOPNOTSUPP>
#include <EOVERFLOW>
#include <EPERM>
#include <EROFS>
#include <ETXTBSY>
#include <EWOULDBLOCK>

namespace linux::open {

enum Error
{
#define _(name) _##name = name
    _(EACCES),
    _(EDQUOT),
    _(EEXIST),
    _(EFAULT),
    _(EINTR),
    _(EINVAL),
    _(EISDIR),
    _(ELOOP),
    _(EMFILE),
    _(ENAMETOOLONG),
    _(ENFILE),
    _(ENODEV),
    _(ENOENT),
    _(ENOSPC),
    _(ENOTDIR),
    _(ENXIO),
    _(EOPNOTSUPP),
    _(EOVERFLOW),
    _(EPERM),
    _(EROFS),
    _(ETXTBSY),
    _(EWOULDBLOCK),
#undef _
};

}