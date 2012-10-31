#ifndef MINIMPL_H_
#define MINIMPL_H_

template <bool Value> struct BoolType
{
	static const bool value = Value;
};

template <unsigned long n, unsigned long m> struct Eq
{
	static const bool value = false;
};

template <unsigned long n> struct Eq<n, n>
{
	static const bool value = true;
};

template <bool Condition, typename First, typename Second> struct If {};

template <typename First, typename Second> struct If<true, First, Second> : public First { };

template <typename First, typename Second> struct If<false, First, Second> : public Second { };

template <unsigned char Power> struct PowerOf2
{
	static const unsigned long value = PowerOf2<Power-1>::value * 2;
};

template <> struct PowerOf2<0>
{
	static const bool value = 1;
};

template <unsigned long n, unsigned char Power> struct TestPowerOf2UpTo
{
	static const bool value =
			If<Eq<n, PowerOf2<Power>::value>::value, BoolType<true>, TestPowerOf2UpTo<n, Power -1> >::value;
};

template <unsigned long n> struct TestPowerOf2UpTo<n, 0>
{
	static const bool value = false;
};



#endif /* MINIMPL_H_ */
