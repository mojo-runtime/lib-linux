#pragma once

#include <Word.hxx>

#define _E(rest) E##rest##_ = E##rest

namespace linux {

template <typename Success, typename Failure>
struct Result
{
    enum Kind { SUCCESS, FAILURE };

    operator
    Kind() const
    {
        return __builtin_expect(this->__word <= 0xFFFFFFFFFFFFF000UL, 1) ? SUCCESS : FAILURE;
    }

    Failure
    failure() const
    {
        return static_cast<Failure>(-this->__word);
    }

    Success
    success() const
    {
        return static_cast<Success>(this->__word);
    }

    //----------------------------------------------------------------------------------------------

    Word
    __word;
};

}
