#pragma once
#include <cstddef>

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
  class iterator
  {
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
    
    private:
        pointer data;
    
    public:
        iterator() : data(NULL) {}
        iterator(value_type *data) : data(data) {}
        iterator(const iterator &other) : data(other.data) {}
        iterator &operator=(const iterator &other) { data = other.data; return *this; }
        iterator &operator++() { ++data; return *this; }
        iterator operator++(int) { iterator tmp(*this); ++data; return tmp; }
        iterator &operator--() { --data; return *this; }
        iterator operator--(int) { iterator tmp(*this); --data; return tmp; }
        reference operator*() { return *data; }
        pointer operator->() { return data; }
        bool operator==(const iterator &other) { return data == other.data; }
        bool operator!=(const iterator &other) { return data != other.data; }
  };
