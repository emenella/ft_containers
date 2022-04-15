#pragma once
#include <cstddef>

namespace ft
{
    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };
}