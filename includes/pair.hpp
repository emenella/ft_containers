//pair.hpp
#pragma once
namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        private:
            T1 first;
            T2 second;
        public:
            pair() : first(first_type), second(second_type) {}
            pair(const T1 &first, const T2 &second) : first(first), second(second) {}
            pair(const pair &other) : first(other.first), second(other.second) {}
            pair &operator=(const pair &other) { first = other.first; second = other.second; return *this; }
    };
}