#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestLab
#include "boost/test/unit_test.hpp"

template<class T> class Ololo
{
public:
	void foo();
};

template<class T> void Ololo<T>::foo()
{
	return;
}

void test(int* & foo)
{
	Ololo<int> lo;
	lo.foo();
}
