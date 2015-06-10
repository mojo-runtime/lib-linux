#pragma once

#include "blkcnt_t.h"
#include "blksize_t.h"
#include "dev_t.h"
#include "gid_t.h"
#include "ino_t.h"
#include "mode_t.h"
#include "off_t.h"
#include "nlink_t.h"
#include "struct-timespec.h" // [XSI]
#include "uid_t.h"

struct stat
{
    //----------------------------------------------------------------------------------------------
    // arch/arm/include/include/uapi/asm/stat.h

#if defined(__arm__)
#  if defined(__ARMEB__)
#    error
#  endif

    dev_t           st_dev;
    ino_t           st_ino;
    mode_t          st_mode;
    nlink_t         st_nlink;
    uid_t           st_uid;
    gid_t           st_gid;
    dev_t           st_rdev;
    off_t           st_size;
    blksize_t       st_blksize;
    blkcnt_t        st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;

    long __pad[2];

    //----------------------------------------------------------------------------------------------
    // arch/x86/include/uapi/asm/stat.h

#elif defined(__x86_64__)

    dev_t           st_dev;
    ino_t           st_ino;
    nlink_t         st_nlink;
    mode_t          st_mode;
    uid_t           st_uid;
    gid_t           st_gid;
    unsigned int    __pad0;
    dev_t           st_rdev;
    off_t           st_size;
    blksize_t       st_blksize;
    blkcnt_t        st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;

    long __pad1[3];

    //----------------------------------------------------------------------------------------------

#else
#  error
#endif
};
