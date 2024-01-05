// std::function ¿¬½À

#include <functional>
#include <iostream>
#include <string>

class A {
	int c;

public:
	A(int c) : c(c) {}
	int foo() {
		std::cout << "non-const function : " << ++c << std::endl;
		return c;
	}

 	int const_foo() const {
		std::cout << "const function : " << c << std::endl;
		return c;
	} 

	static void st() {}
};

int main() {
	A a(5);
	std::function<int(A&)> f1 = &A::foo;
	std::function<int(const A&)> f2 = &A::const_foo;

	f1(a);
	f2(a);
}