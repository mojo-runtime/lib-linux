#pragma once

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"

#if defined(__has_attribute)
#  define __has_attribute_nothrow __has_attribute(nothrow)
#elif defined(__GNUC__) // Version?
#  define __has_attribute_nothrow ((__GNUC__ >= 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)))
#else
#  error
#endif

#if __has_attribute_nothrow
#  define __nothrow __attribute__((__nothrow__))
#else
#  error
#endif

#pragma clang diagnostic pop