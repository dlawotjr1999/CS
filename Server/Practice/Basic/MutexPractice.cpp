#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
	for (int i = 0; i < 10000; i++) {
		m.lock();
		result += 1;
		m.unlock();	// unlock을 호출하지 않을 시 쓰레드들이 임계공간에 진입할 수 없으므로 deadlock에 빠짐

		// 위와 동일한 기능을 함
		// std::lock_guard<std::mutex> lock(m);
		// result += 1;
	}
}

int main() {
	int counter = 0;
	std::mutex m;

	// 쓰레드는 기본적으로 call-by-value이기 때문에 레퍼런스 파라미터를 직접 전달하려면 std::ref로 감싸 전달해야 함
	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.emplace_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	std::cout << "Counter : " << counter;
}