#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

void worker(std::atomic<int>& counter) {
	for (int i = 0; i < 10000; i++) {
		counter++;
	}
}

int main() {
	std::atomic<int> counter(0);

	std::vector<std::thread> workers;
	for (int i = 0; i < 5; i++) {
		workers.emplace_back(std::thread(worker, std::ref(counter)));
	}

	for (int i = 0; i < 5; i++) {
		workers[i].join();
	}

	std::cout << "counter : " << counter;
}