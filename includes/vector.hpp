#pragma once
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
#include "exception.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

            typedef ft::iterator<ft::random_access_iterator_tag, value_type> iterator;
            typedef ft::iterator<ft::random_access_iterator_tag, const value_type> const_iterator;
            typedef ft::reverse_iterator<iterator, value_type> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator, value_type> const_reverse_iterator;
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef size_t size_type;
        

        private:
            pointer _data;
            size_t _size;
            size_t _capacity;
            allocator_type _alloc;

        public:
            vector() : _data(NULL), _size(0), _capacity(0) {}
            vector(const vector &other) : _data(other._data), _size(other._size), _capacity(other._capacity) {}
            vector &operator=(const vector &other) { _data = other._data; _size = other._size; _capacity = other._capacity; return *this; }
            ~vector() {}
            
            //Iterators
            iterator begin() { return iterator(_data); }
            iterator end() { return iterator(_data + _size); }
            reverse_iterator rbegin() { return reverse_iterator(_data); }
            reverse_iterator rend() { return reverse_iterator(_data + _size); }

            //Capacity
            int size() const { return _size; }
            bool empty() const { return _size == 0; }
            int capacity() const { return _capacity; }
            void reserve(size_type new_cap) { if (new_cap > _capacity) reallocate(new_cap); }
            void resize(size_type new_size) {
                if (new_size > _capacity)
                    reserve(new_size);
                _size = new_size;
            }
            void reallocate(size_t new_capacity)
            {
                pointer new_data = _alloc.allocate(new_capacity);
                pointer old_data = _data;
                for (size_t i = 0; i < _size; ++i)
                    _alloc.construct(&new_data[i], old_data[i]);
                _data = new_data;
                _capacity = new_capacity;
                _alloc.deallocate(old_data, _capacity);
            }

            //Element access
            reference operator[](size_type index) { return _data[index]; }
            const_reference operator[](size_type index) const { return _data[index]; }
            reference at(size_type index) { if (index >= _size) { throw exception("Index out of range"); } return _data[index]; }
            const_reference at(size_type index) const { if (index >= _size) { throw exception("Index out of range"); } return _data[index]; }
            reference front() { return _data[0]; }
            const_reference front() const { return _data[0]; }
            reference back() { return _data[_size - 1]; }
            const_reference back() const { return _data[_size - 1]; }

            //Modifiers
            void push_back(const value_type &value) { if (_size == _capacity) reallocate(_capacity * 2); _alloc.construct(&_data[_size], value); _size++; }
            void pop_back() { if (size > 0) { _size--; } }
            void clear() { size = 0; }
            void swap(vector &other)
            { 
                ft::swap(_data, other._data);
                ft::swap(_size, other._size);
                ft::swap(_capacity, other._capacity);
            }

    };
}
