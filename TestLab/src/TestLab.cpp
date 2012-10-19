#include <iostream>
#include <boost/test/included/prg_exec_monitor.hpp>

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

#include <boost/array.hpp>

#include "Structures/sorting.h"

using namespace std;
using namespace boost;

//____________________________________________________________________________//

int cpp_main( int, char* [] )
{
    return 0;
}

//____________________________________________________________________________//



template <class Ch, class Tr, class T> void print_val(basic_ostream<Ch, Tr>&  stream, T val)
{
	cout << val << " ";
}

template <class Ch, class Tr, class Con> basic_ostream<Ch, Tr>& operator <<(basic_ostream<Ch, Tr>&  stream, Con container) {
	for_each(container.begin(), container.end(), bind1st(ptr_fun(print_val<Ch, Tr, typename Con::value_type>), stream));
	return stream;
}

int old_main() {

	array<int, 5> v;

	//vector<int> v(5, 1);

	partial_sum(v.begin(), v.end(), v.begin());

	transform(v.begin(), v.end(), v.begin(), bind1st(multiplies<int>(), 10));

	cout << v << endl;

	return 0;
}



