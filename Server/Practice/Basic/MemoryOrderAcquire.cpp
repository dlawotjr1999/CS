#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

// memory_order_release : �ش� ��� ������ ��� �޸� ��ɵ��� �ش� ��� ���ķ� ���ġ�Ǵ� ���� ������
// memory_order_acquire : �ش� ��� �ڿ� ���� ��� �޸� ��ɵ��� �ش� ��� ���� ���ġ�Ǵ� ���� ������
// memory_order_release�� write -> store�� ������ �����ϸ�, memory_order_acquire�� load -> read�� ������ ������

// memory_order_acq_rel : acquire�� release ��� ����. fetch_add�� ���� �Լ����� ���� �� ����

std::atomic<bool> is_ready;
std::atomic<int> data[3];

void producer() {
	// �����͸� store�ϴ� ������� memory_order_relaxed�̱� ������ �����Ӱ� ���ġ�� �� ����
	// �׷��� is_ready �������� ���ġ�� ������
	data[0].store(1, std::memory_order_relaxed);
	data[1].store(2, std::memory_order_relaxed);
	data[2].store(3, std::memory_order_relaxed);
	is_ready.store(true, std::memory_order_release);
}

void consumer() {
	// �����Ͱ� �غ�� ������ ��ٸ�
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