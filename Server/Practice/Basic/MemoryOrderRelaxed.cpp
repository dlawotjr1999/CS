#include <cstdio>
#include <vector>
#include <thread>
#include <atomic>

// memory_order_relaxed : �� ������� �޸𸮿��� �аų� �� ���, ������ �ٸ� �޸� ���� ������ �ٲ��� ������

void t1(std::atomic<int>* a, std::atomic<int>* b) {
	b->store(1, std::memory_order_relaxed);		// b=1; (write)
	int x = a->load(std::memory_order_relaxed); // x=a; (read)

	printf("x : %d\n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b) {
	a->store(1, std::memory_order_relaxed);		// a=1;
	int y = b->load(std::memory_order_relaxed); // y=b;

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
