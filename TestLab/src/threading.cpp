#include <iostream>
#include "boost/thread.hpp"

using namespace boost;

void async()
{
	std::cout << "brb";
}

int main()
{
	thread t(async);
	t.join();

	return 0;
}
