#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

// memory_order_release : 해당 명령 이전의 모든 메모리 명령들이 해당 명령 이후로 재배치되는 것을 금지함
// memory_order_acquire : 해당 명령 뒤에 오는 모든 메모리 명령들이 해당 명령 위로 재배치되는 것을 금지함
// memory_order_release는 write -> store의 순서를 보장하며, memory_order_acquire는 load -> read의 순서를 보장함

// memory_order_acq_rel : acquire와 release 모두 수행. fetch_add와 같은 함수에서 사용될 수 있음

std::atomic<bool> is_ready;
std::atomic<int> data[3];

void producer() {
	// 데이터를 store하는 연산들은 memory_order_relaxed이기 때문에 자유롭게 재배치될 수 있음
	// 그러나 is_ready 위에서만 재배치가 가능함
	data[0].store(1, std::memory_order_relaxed);
	data[1].store(2, std::memory_order_relaxed);
	data[2].store(3, std::memory_order_relaxed);
	is_ready.store(true, std::memory_order_release);
}

void consumer() {
	// 데이터가 준비될 때까지 기다림
	while (!is_ready.load(std::memory_order_acquire));

	std::cout << "data[0] : " << data[0].load(std::memory_order_relaxed);
	std::cout << "data[1] : " << data[1].load(std::memory_order_relaxed);
	std::cout << "data[2] : " << data[2].load(std::memory_order_relaxed);
}

int main() {
	std::vector<std::thread> threads;

	threads.push_back(std::thread(producer));
	threads.push_back(std::thread(consumer));

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
}