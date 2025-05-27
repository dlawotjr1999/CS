#include <iostream>
#include <future>
#include <thread>
#include <chrono>

void runner(std::shared_future<void>* start) {
	start->get();
	std::cout << "start!" << std::endl;
}

int main() {
	std::promise<void> p;
	std::shared_future<void> start = p.get_future();

	std::thread t1(runner, &start);
	std::thread t2(runner, &start);
	std::thread t3(runner, &start);
	std::thread t4(runner, &start);

	std::cerr << "ready...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "go!" << std::endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
