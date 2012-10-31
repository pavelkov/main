#ifndef BASIC_H_
#define BASIC_H_

#include <limits>
#include "minimpl.h"

template <unsigned long Argument> struct ModuloFunction
{
	static unsigned long eval(unsigned long num)
	{
		return num % Argument;
	}
};

template <unsigned long Argument> struct BitwiseAndFunction
{
	static unsigned long eval(unsigned long num)
	{
		return num & Argument;
	}
};

template <unsigned long n> struct Modulo
{
public:

	Modulo(Modulo<n> &other) : value(other.value) { };

	Modulo(unsigned long intValue) // implicit, because we do want module to be treated as ulong
		: value(ModImpl::eval(intValue)) { };

	operator unsigned long() {return value;}

	void operator ++() { value = ModImpl::eval(value + 1); }

	void operator --() { value = ModImpl::eval(value - 1); }

private:
	static const unsigned char maxPower = std::numeric_limits<unsigned long>::digits - 1;
	static const bool isPowerOf2 = TestPowerOf2UpTo<n, maxPower>::value;
	typedef If<isPowerOf2, BitwiseAndFunction<n - 1>, ModuloFunction<n> > ModImpl;
	unsigned long value;
};


#endif /* BASIC_H_ */
