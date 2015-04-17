#pragma once

#include "c/EPOLL_CLOEXEC.h"
#include "c/EPOLL_CTL_ADD.h"
#include "c/EPOLL_CTL_DEL.h"
#include "c/EPOLL_CTL_MOD.h"
#include "c/EPOLLERR.h"
#include "c/EPOLLET.h"
#include "c/EPOLLHUP.h"
#include "c/EPOLLIN.h"
#include "c/EPOLLONESHOT.h"
#include "c/EPOLLOUT.h"
#include "c/EPOLLPRI.h"
// EPOLLRDBAND
// EPOLLRDNORM
// EPOLLRDHUP
// EPOLLWRBAND
// EPOLLWRNORM
#include "c/EPOLLWAKEUP.h"
#include "c/epoll_data_t.h"
#include "c/struct epoll_event.h"
// epoll_create
// epoll_create1
// epoll_ctl
// epoll_pwait
// epoll_wait
