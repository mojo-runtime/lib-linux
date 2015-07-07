#pragma once

namespace linux { inline namespace _x86_64 {

using Word = unsigned long;

template <Word number>
static inline
auto
_call() noexcept
{
    Word result;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1>
static inline
auto
_call(A1 a1) noexcept
{
    Word result;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1, typename A2>
static inline
auto
_call(A1 a1, A2 a2) noexcept
{
    Word result;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1), "S" (a2)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1, typename A2, typename A3>
static inline
auto
_call(A1 a1, A2 a2, A3 a3) noexcept
{
    Word result;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1), "S" (a2), "d" (a3)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1, typename A2, typename A3, typename A4>
static inline
auto
_call(A1 a1, A2 a2, A3 a3, A4 a4) noexcept
{
    Word result;

    register auto r10 asm ("r10") = a4;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1), "S" (a2), "d" (a3), "r" (r10)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1, typename A2, typename A3, typename A4, typename A5>
static inline
auto
_call(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) noexcept
{
    Word result;

    register auto r10 asm ("r10") = a4;
    register auto r8  asm ("r8")  = a5;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8)
        : "rcx", "r11"
    );

    return result;
}

template <Word number, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
static inline
auto
_call(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) noexcept
{
    Word result;

    register auto r10 asm ("r10") = a4;
    register auto r8  asm ("r8")  = a5;
    register auto r9  asm ("r9")  = a6;

    asm volatile (
        "syscall"
        : "=a" (result)
        : "a" (number), "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8), "r" (r9)
        : "rcx", "r11"
    );

    return result;
}

}}
