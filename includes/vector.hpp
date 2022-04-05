#pragma once

namespace ft
{
    template < class T, class Alloc>
    class vector
    {
        private:
            typedef T value_type;
            typedef typename Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //to do Iterator 

        public:
    };
}
