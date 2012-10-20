#include <iostream>
#include <vector>
#include <numeric>

#include <boost/array.hpp>

#include "Structures/sorting.h"
#include "Structures/helper.h"

using namespace std;


int old_main( int argc, char* argv[] )
{
	boost::array<int, 5> v;

	v.fill(1);
	partial_sum(v.begin(), v.end(), v.begin());

	transform(v.begin(), v.end(), v.begin(), bind1st(multiplies<int>(), 10));

	cout << v << endl;

	return 0;
}
