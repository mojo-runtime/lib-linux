#pragma once

#define _E(rest) E##rest##_ = E##rest

namespace linux {

using Word = decltype(sizeof(int));

template <typename Ok, typename Error>
struct Result
{
    explicit
    operator
    bool() const
    {
        return this->__word > 0xFFFFFFFFFFFFF000UL;
    }

    Error
    error() const
    {
        return static_cast<Error>(-this->__word);
    }

    Ok
    ok() const
    {
        return static_cast<Ok>(this->__word);
    }

    //----------------------------------------------------------------------------------------------

    Word
    __word;
};

}
