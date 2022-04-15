//enable_if.hpp
#pragma once

namespace ft {
    template <bool B, class T = void>
    struct enable_if
    {
    };
}