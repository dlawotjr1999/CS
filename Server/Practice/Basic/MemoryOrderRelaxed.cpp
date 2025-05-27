#include <cstdio>
#include <vector>
#include <thread>
#include <atomic>

// memory_order_relaxed : 이 방식으로 메모리에서 읽거나 쓸 경우, 주위의 다른 메모리 접근 순서가 바껴도 무방함

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
