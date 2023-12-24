// Folding 연산자 연습

#include <iostream>

template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

template <typename String>
std::string StrCat(const String& s) {
	return std::string(s);
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

template<typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
	return std::string(s) + StrCat(strs...);
}

//std:c17 Unary left fold
template <typename... Ints>
int sum_all(Ints... nums) {
	return (... + nums);
}

//std:c17  Binary left fold
template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
	return (start - ... - nums);
}

template <typename... Ints>
double average(Ints... nums) {
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main() {
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), " ", std::string("sentence"), "\n");

	std::cout << average(1, 4, 6, 7, 11, 13) << std::endl;

	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;
}