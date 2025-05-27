#include <iostream>
#include <mutex>
#include <thread>

// 참고 : 일반적으로 하나의 공유 자원을 보호하기 위해 하나의 mutex를 사용함
// 여기서는 deadlock을 표현하기 위해 두 개의 mutex를 사용함

void worker1(std::mutex& m1, std::mutex& m2) {
	for (int i = 0; i < 100; i++) {
		m1.lock();
		m2.lock();

		std::cout << "worker1 critical section " << i << '\n';

		m2.unlock();
		m1.unlock();
	}
}

void worker2(std::mutex& m1, std::mutex& m2) {
	for (int i = 0; i < 100; i++) {
		while (true) {
			// m2는 문제없이 lock이 가능
			// 하지만 worker1의 m2.lock()이 먼저 선행된 경우에는 일시적으로 block 상태가 됨
			m2.lock();

			// try_lock : lock이 가능할 경우 lock을 하고 true를 리턴. lock이 불가능한 경우에는 그냥 false를 리턴
			// 즉 false를 리턴하는 경우에는 m1이 이미 잠겨있다는 의미이므로, 우선권이 있는 worker1에 m2를 양보해야 함 
			if (!m1.try_lock()) {
				m2.unlock();
				continue;
			}

			std::cout << "worker2 critical section " << i << '\n';

			m1.unlock();
			m2.unlock();
			break;
		}
	}
}

int main() {
	std::mutex m1, m2;

	std::thread t1(worker1, std::ref(m1), std::ref(m2));
	std::thread t2(worker2, std::ref(m1), std::ref(m2));

	t1.join();
	t2.join();

	std::cout << "End...";
}