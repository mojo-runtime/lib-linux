#pragma once

namespace linux { inline namespace _arm {

using Word = unsigned long;

template <Word number>
static inline
Word
_call() noexcept
{
    register auto r0 asm ("r0") = number;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1>
static inline
Word
_call(A1 a1) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1, typename A2>
static inline
Word
_call(A1 a1, A2 a2) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;
    register auto r2 asm ("r2") = a2;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1), "r" (r2)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1, typename A2, typename A3>
static inline
Word
_call(A1 a1, A2 a2, A3 a3) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;
    register auto r2 asm ("r2") = a2;
    register auto r3 asm ("r3") = a3;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1), "r" (r2), "r" (r3)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1, typename A2, typename A3, typename A4>
static inline
Word
_call(A1 a1, A2 a2, A3 a3, A4 a4) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;
    register auto r2 asm ("r2") = a2;
    register auto r3 asm ("r3") = a3;
    register auto r4 asm ("r4") = a4;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1), "r" (r2), "r" (r3), "r" (r4)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1, typename A2, typename A3, typename A4, typename A5>
static inline
Word
_call(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;
    register auto r2 asm ("r2") = a2;
    register auto r3 asm ("r3") = a3;
    register auto r4 asm ("r4") = a4;
    register auto r5 asm ("r5") = a5;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1), "r" (r2), "r" (r3), "r" (r4), "r" (r5)
        : "memory"
    );

    return r0;
}

template <Word number, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
static inline
Word
_call(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) noexcept
{
    register auto r0 asm ("r0") = number;
    register auto r1 asm ("r1") = a1;
    register auto r2 asm ("r2") = a2;
    register auto r3 asm ("r3") = a3;
    register auto r4 asm ("r4") = a4;
    register auto r5 asm ("r5") = a5;
    register auto r6 asm ("r6") = a6;

    asm volatile (
        "swi 0x0"
        : "=r" (r0)
        : "r" (r0), "r" (r1), "r" (r2), "r" (r3), "r" (r4), "r" (r5), "r" (r6)
        : "memory"
    );

    return r0;
}

}}
