#pragma once

typedef enum
{
    // LINUX/include/uapi/linux/wait.h
    // (The kernel defines these as macros.)
    P_ALL,
    P_PID,
    P_PGID
}
idtype_t;
