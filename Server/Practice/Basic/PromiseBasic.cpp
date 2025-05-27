#include <iostream>
#include <future>
#include <thread>

void worker(std::promise<std::string>* p) {
	p->set_value("some data");
}

int main() {
	std::promise<std::string> p;
	std::future<std::string> data = p.get_future();

	std::thread t(worker, &p);
	data.wait();

	std::cout << data.get() << '\n';
	t.join();
}