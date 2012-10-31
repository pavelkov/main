#include <iostream>
#include <numeric>

#define BOOST_TEST_DYN_LINK
#define BOOST_DEPRECATED
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE TestLab
#endif
#include "boost/test/unit_test.hpp"

#include "linked_list.h"
#include "basic.h"

template <class Ch, class Tr, class T>
	void print_val(std::basic_ostream<Ch, Tr>&  stream, T val)
{
	stream << val << " ";
}

template <class Ch, class Tr, class Con> void print_container(std::basic_ostream<Ch, Tr>&  stream, Con container) {
	std::for_each(container.begin(), container.end(),
			std::bind1st(std::ptr_fun(print_val<Ch, Tr, typename Con::value_type>),
			stream));
}

BOOST_AUTO_TEST_SUITE(Structures)

BOOST_AUTO_TEST_SUITE(LinkedList)

BOOST_AUTO_TEST_CASE(BasicUsage)
{
	structures::linked_list<int> l;

	structures::linked_list<int>::iterator it = l.begin();
	for(int i = 0; i < 5; ++ i)
		it = l.insert_after(it, i);

	print_container(std::cout, l);
	std::cout << "min:" << *(std::min_element(l.begin(), l.end()));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Basic)

BOOST_AUTO_TEST_CASE(BasicUsage)
{
	Modulo<8> m8(12);

	std::cout << m8 << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
