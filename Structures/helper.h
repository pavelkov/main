#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <algorithm>
#include <functional>

template <class Ch, class Tr, class T>
	void print_val(std::basic_ostream<Ch, Tr>&  stream, T val)
{
	stream << val << " ";
}

template <class Ch, class Tr, class Con> std::basic_ostream<Ch, Tr>&
	operator <<(std::basic_ostream<Ch, Tr>&  stream, Con container) {
	std::for_each(container.begin(), container.end(),
			std::bind1st(std::ptr_fun(print_val<Ch, Tr, typename Con::value_type>),
			stream));
	return stream;
}

#endif
