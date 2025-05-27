#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
	for (int i = 0; i < 10000; i++) {
		m.lock();
		result += 1;
		m.unlock();	// unlock�� ȣ������ ���� �� ��������� �Ӱ������ ������ �� �����Ƿ� deadlock�� ����

		// ���� ������ ����� ��
		// std::lock_guard<std::mutex> lock(m);
		// result += 1;
	}
}

int main() {
	int counter = 0;
	std::mutex m;

	// ������� �⺻������ call-by-value�̱� ������ ���۷��� �Ķ���͸� ���� �����Ϸ��� std::ref�� ���� �����ؾ� ��
	std::vector<std::thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.emplace_back(std::thread(worker, std::ref(counter), std::ref(m)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	std::cout << "Counter : " << counter;
}