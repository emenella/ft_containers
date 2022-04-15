#pragma once
#include <cstddef>
#include "iterator_traits.hpp"

namespace ft {

  template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator
    {
      public:
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
      
      private:
          pointer data;
      
      public:
            iterator(value_type *data) : data(data) {}
            iterator() : data(NULL) {}
            iterator &operator=(const iterator &other) { data = other.data; return *this; }
            iterator &operator++() { ++data; return *this; }
            iterator operator++(int) { iterator tmp(*this); ++data; return tmp; }
          
            bool operator==(const iterator &other) { return data == other.data; }
            bool operator!=(const iterator &other) { return data != other.data; }
            reference operator*() { return *data; }
            pointer operator->() { return data; }
            iterator &operator--() { --data; return *this; }
            iterator operator--(int) { iterator tmp(*this); --data; return tmp; }

            iterator operator+(const difference_type &n) { return iterator(data + n); }
            iterator operator-(const difference_type &n) { return iterator(data - n); }
            bool operator<(const iterator &other) { return data < other.data; }
            bool operator>(const iterator &other) { return data > other.data; }
            bool operator<=(const iterator &other) { return data <= other.data; }
            bool operator>=(const iterator &other) { return data >= other.data; }
            iterator &operator+=(const difference_type &n) { data += n; return *this; }
            iterator &operator-=(const difference_type &n) { data -= n; return *this; }
            iterator &operator[](int index) { return data[index]; }
    };
}
