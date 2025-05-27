#include <iostream>
#include <mutex>
#include <thread>

// ���� : �Ϲ������� �ϳ��� ���� �ڿ��� ��ȣ�ϱ� ���� �ϳ��� mutex�� �����
// ���⼭�� deadlock�� ǥ���ϱ� ���� �� ���� mutex�� �����

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
			// m2�� �������� lock�� ����
			// ������ worker1�� m2.lock()�� ���� ����� ��쿡�� �Ͻ������� block ���°� ��
			m2.lock();

			// try_lock : lock�� ������ ��� lock�� �ϰ� true�� ����. lock�� �Ұ����� ��쿡�� �׳� false�� ����
			// �� false�� �����ϴ� ��쿡�� m1�� �̹� ����ִٴ� �ǹ��̹Ƿ�, �켱���� �ִ� worker1�� m2�� �纸�ؾ� �� 
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