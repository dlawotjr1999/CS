// TMP(Template Meta Programming) ¿¬½À

#include <iostream>

template<int N>
struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template<>
struct Factorial<1> {
	static const int result = 1;
};

template <int X, int Y>
struct GCD {
	static const int value = GCD<Y, X% Y>::value;
};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
	typedef Ratio<N, D> type;
	static const int num = N;
	static const int den = D;
};

template <class R1, class R2>
struct _Ratio_add {
	typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den> type;
};

template<class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
	std::cout << "5! = " << Factorial<5>::result << std::endl;
	std::cout << "gcd(36,24) :: " << GCD<36, 24>::value << std::endl;

	typedef Ratio<2, 3> rat;
	typedef Ratio<3, 2> rat2;
	typedef Ratio_add<rat, rat2> rat3;

	std::cout << rat3::num << "/" << rat3::den << std::endl;

	return 0;
}