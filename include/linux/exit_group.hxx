#pragma once

#include <SYS_exit_group>
#include "__call.hxx"

namespace linux {

[[noreturn]]
static inline
void
exit_group(int status) noexcept
{
    __call<SYS_exit_group>(status);
    __builtin_unreachable();
};

}
