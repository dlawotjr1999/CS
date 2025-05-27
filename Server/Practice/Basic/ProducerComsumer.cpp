#include <chrono>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <thread>
#include <vector>

// ���� ���� : Ư�� ������ ������ ������ �����带 ���� �ߴٰ�, ������ �����Ǹ� ����� ����ȭ ����

void producer(std::queue<std::string>* download_pages, std::mutex* m, int index, std::condition_variable &cv) {
	for (int i = 0; i < 5; i++) {
		// ������Ʈ���� �ٿ�ε��ϴ� �� �ɸ��� �ð����� �ùķ��̼�
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "������Ʈ : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";
	
		m->lock();
		download_pages->push(content);
		m->unlock();

		// notify �Լ� : ���� �����尡 ���� �ڿ��� ���¸� ������ ��, ��ٸ��� �ִ� �ٸ� �����忡�� ������ �����Ǿ����� �˷��ִ� ����� ����
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* download_pages, std::mutex* m, int* num_processed, std::condition_variable &cv) {
	while (*num_processed < 25) {
		// ���� ������ unique_lock�� ���ڷ� ����
		// ���� lock_guard�� �ٸ��� unlock �� �ٽ� lock�� ����
		std::unique_lock<std::mutex> lk(*m);

		// wait �Լ� : ���ڷ� �־��� ������ true�� �� ������ ��ٸ�
		// �� �־��� ������ true�̸� �����尡 ���
		cv->wait(lk, [&] { return !download_pages->empty() || *num_processed == 25; });

		// wait�� Ż���� ������ ��� �������� ó���ؼ������� Ȯ���ϱ� ���� �߰� ���� �ʿ�
		// ��� �������� ó���� ��쿡�� �����带 �����ϸ� ��
		// �׷��� ���� �����, queue�� �ִ� �������� ó���ϸ� ��
		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		std::string content = download_pages->front();
		download_pages->pop();

		(*num_processed)++;
		m->unlock();

		std::cout << content;
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}

int main() {
	std::queue<std::string> download_pages;
	std::mutex m;

	// ���� ���� ����
	std::condition_variable cv;

	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.emplace_back(std::thread(producer, &download_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	std::vector<std::thread> consumers;
	std::vector<std::thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.emplace_back(std::thread(producer, &download_pages, &m, num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}

	// producer���� ��� ���� ���� �������� �ڰ� �ִ� consumer���� ���� �� �����Ƿ� ��� ����
	// �����ִ� ���¿��� join�� �����ϱ� ���� 
	cv.notify_all();

	for (int i = 0; i < 5; i++) {
		consumers[i].join();
	}
}