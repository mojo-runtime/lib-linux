#ifndef c_EPOLL_CTL_ADD_h_
#define c_EPOLL_CTL_ADD_h_

#include "c/__c_namespace.h"

__c_namespace_open

static
const int
EPOLL_CTL_ADD =
#ifdef __linux__
 1
#else
#  error
#endif
 ;

__c_namespace_close

#endif
