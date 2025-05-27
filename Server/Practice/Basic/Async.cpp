#include <iostream>
#include <vector>
#include <future>
#include <thread>

int sum(const std::vector<int>& vec, int start, int end) {
	int total = 0;
	for (int i = start; i < end; i++) {
		total = vec[i];
	}
	return total;
}

int parallel_sum(const std::vector<int> vec) {
	std::future<int> lower_half_future =
		std::async(std::launch::async, sum, cref(vec), 0, vec.size() / 2);
	int upper_half = sum(vec, vec.size() / 2, vec.size());

	return lower_half_future.get() + upper_half;
}

int main() {
	std::vector<int> vec;
	vec.reserve(1000);

	for (int i = 0; i < 1000; i++) {
		vec.push_back(i + 1);
	}
	std::cout << "sum from 1 to 1000 : " << parallel_sum(vec) << std::endl;
}