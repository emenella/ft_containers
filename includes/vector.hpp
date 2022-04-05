#pragma once

#include "includes/iterator.hpp"
#include "includes/reverse_iterator.hpp"
#include "includes/utils.hpp"

namespace ft
{
    template < class T, class Alloc>
    class vector
    {
        typedef T value_type;
        typedef typename Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;

        private:
            pointer data;
            size_t size;
            size_t capacity;
            allocator_type alloc;

        public:
            vector() : data(NULL), size(0), capacity(0) {};
            vector(const vector &other) : data(other.data), size(other.size), capacity(other.capacity) {};
            vector &operator=(const vector &other) { data = other.data; size = other.size; capacity = other.capacity; return *this; };
            ~vector() {};
            
            //Iterators
            iterator begin() { return iterator(data); };
            iterator end() { return iterator(data + size); };
            reverse_iterator rbegin() { return reverse_iterator(data); };
            reverse_iterator rend() { return reverse_iterator(data + size); };

            //Capacity
            int size() const { return size; };
            bool empty() const { return size == 0; };
            int capacity() const { return capacity; };
            void reserve(size_t new_cap) { if (new_cap > capacity) { reallocate(new_cap); } };
            void resize(size_t new_size) { if (new_size > size) { reallocate(new_size); } };

            //Element access
            reference operator[](size_t index) { return data[index]; };
            const_reference operator[](size_t index) const { return data[index]; };
            reference at(size_t index) { if (index >= size) { throw std::out_of_range("Index out of range"); } return data[index]; };
            const_reference at(size_t index) const { if (index >= size) { throw std::out_of_range("Index out of range"); } return data[index]; };
            reference front() { return data[0]; };
            const_reference front() const { return data[0]; };
            reference back() { return data[size - 1]; };
            const_reference back() const { return data[size - 1]; };

            //Modifiers
            void push_back(const value_type &value) { if (size == capacity) { std::allocate(size + 1); } data[size++] = value; };
            void pop_back() { if (size > 0) { size--; } };
            void clear() { size = 0; };
            void swap(vector &other)
            { 
                ft::swap(data, other.data);
                ft::swap(size, other.size);
                ft::swap(capacity, other.capacity);
            };

    };
}
