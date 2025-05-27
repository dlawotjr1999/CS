#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; itr++) {
		sum += *itr;
	}
	*result = sum;

	// 쓰레드의 id를 구함
	thread::id this_id = this_thread::get_id();

	// std::cout 대신 printf를 사용하는 이유
	// printf 함수는 context-switching이 발생하더라도 다른 쓰레드들이 그 사이에 메세지를 집어넣지 못하게 하기 때문
	printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);
}

int main() {
	vector<int> vec(100000);
	for (int i = 0; i < 100000; i++) {
		vec[i] = i + 1;
	}

	// 각 쓰레드들에서 계산된 합을 저장하는 벡터
	vector<int> partial_sums(4);

	// 쓰레드에 인자를 전달하려면 std::bind와 유사하게 사용하면 됨. 즉 첫 번째 인자로는 함수를, 이후에는 그 함수의 parameter를 전달.
	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.emplace_back(thread(worker, vec.begin() + i * 2500, vec.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i = 0; i < 4; i++)
		workers[i].join();

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	std::cout << "전체 합 : " << total << std::endl;
}