#pragma once
#include "iterator_traits.hpp"

template<class Category, class T, class Distance, class Pointer, class Reference>
struct ft::base_iterator
{
	typedef T			value_type;
	typedef Distance 	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category 	iterator_category;
};