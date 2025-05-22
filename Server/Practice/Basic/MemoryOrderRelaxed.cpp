#include <cstdio>
#include <vector>
#include <thread>
#include <atomic>

void t1(std::atomic<int>* a, std::atomic<int>* b) {
	b->store(1, std::memory_order_relaxed);
	int x = a->load(std::memory_order_relaxed);

	printf("x : %d\n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) {
	a->store(1, std::memory_order_relaxed);
	int y = b->load(std::memory_order_relaxed);

	printf("y : %d\n", y);
}

int main() {
	std::vector<std::thread> threads;

	std::atomic<int> a(0);
	std::atomic<int> b(0);

	threads.emplace_back(std::thread(t1, &a, &b));
	threads.emplace_back(std::thread(t2, &a, &b));

	for (int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
}
