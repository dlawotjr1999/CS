#include <chrono>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <thread>
#include <vector>

// 조건 변수 : 특정 조건이 만족될 때까지 쓰레드를 잠들게 했다가, 조건이 충족되면 깨우는 동기화 도구

void producer(std::queue<std::string>* download_pages, std::mutex* m, int index, std::condition_variable &cv) {
	for (int i = 0; i < 5; i++) {
		// 웹사이트에서 다운로드하는 데 걸리는 시간으로 시뮬레이션
		std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";
	
		m->lock();
		download_pages->push(content);
		m->unlock();

		// notify 함수 : 현재 쓰레드가 공유 자원의 상태를 변경한 후, 기다리고 있던 다른 쓰레드에게 조건이 충족되었음을 알려주는 기능을 수행
		cv->notify_one();
	}
}

void consumer(std::queue<std::string>* download_pages, std::mutex* m, int* num_processed, std::condition_variable &cv) {
	while (*num_processed < 25) {
		// 조건 변수는 unique_lock을 인자로 받음
		// 또한 lock_guard와 다르게 unlock 후 다시 lock이 가능
		std::unique_lock<std::mutex> lk(*m);

		// wait 함수 : 인자로 주어진 조건이 true가 될 때까지 기다림
		// 즉 주어진 조건이 true이면 쓰레드가 깨어남
		cv->wait(lk, [&] { return !download_pages->empty() || *num_processed == 25; });

		// wait를 탈출한 이유가 모든 페이지를 처리해서인지를 확인하기 위해 추가 검토 필요
		// 모든 페이지를 처리한 경우에는 쓰레드를 종료하면 됨
		// 그렇지 않은 경우라면, queue에 있는 페이지를 처리하면 됨
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

	// 조건 변수 선언
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

	// producer들이 모든 일을 끝낸 시점에서 자고 있는 consumer들이 있을 수 있으므로 모두 깨움
	// 깨어있는 상태에서 join이 가능하기 때문 
	cv.notify_all();

	for (int i = 0; i < 5; i++) {
		consumers[i].join();
	}
}