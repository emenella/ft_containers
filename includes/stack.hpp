#include "vector.hpp"

namespace ft
{    
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef typename Container::size_type size_type;

        protected:
            Container c;
        public:
            stack() {}
            stack(const stack& src) { *this = src; }
            stack<T, Container>& operator=(const stack<T, Container>& rhs)
            {
                this->c = rhs.c;
                return *this;
            }
            ~stack() {}
            void push(const value_type& value) { this->c.push_back(value); }
            void pop() { this->c.pop_back(); }
            value_type& top() { return this->c.back(); }
            const value_type& top() const { return this->c.back(); }
            size_type size() const { return this->c.size(); }
            bool empty() const { return this->c.empty(); }
    };
}