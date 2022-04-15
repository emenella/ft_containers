#pragma once
#include <cstddef>

namespace ft
{
  template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class reverse_iterator
    {
      typedef T         value_type;
      typedef Distance  difference_type;
      typedef Pointer   pointer;
      typedef Reference reference;
      typedef Category  iterator_category;
      
      private:
          pointer data;
      
      public:
          reverse_iterator() : data(NULL) {}
          reverse_iterator(value_type *data) : data(data) {}
          reverse_iterator(const reverse_iterator &other) : data(other.data) {}
          reverse_iterator &operator=(const reverse_iterator &other) { data = other.data; return *this; }
          reverse_iterator &operator++() { --data; return *this; }
          reverse_iterator operator++(int) { reverse_iterator tmp(*this); --data; return tmp; }
          reverse_iterator &operator--() { ++data; return *this; }
          reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++data; return tmp; }
          reference operator*() { return *data; }
          pointer operator->() { return data; }
          bool operator==(const reverse_iterator &other) { return data == other.data; }
          bool operator!=(const reverse_iterator &other) { return data != other.data; }
    };
}
