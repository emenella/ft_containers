#pragma once
#include <iostream>

namespace ft 
{
    class exception
    {
        private:
            std::string msg;
        public:
            exception(std::string msg) : msg(msg) {}
            exception(const exception &other) { msg = other.msg; }
            exception &operator=(const exception &other) { msg = other.msg; return *this; }
            virtual ~exception() {}
            virtual const char *what() const throw() { return msg.c_str(); }
    };
}