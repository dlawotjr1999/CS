#include <iostream>
#include <future>
#include <thread>
#include <exception>

void worker(std::promise<std::string>* p) {
	try {
		throw std::runtime_error("Some Error...");
	}
	catch (...) {
		p->set_exception(std::current_exception());
	}
}

int main() {
	std::promise<std::string> p;
	std::future<std::string> data = p.get_future();

	std::thread t(worker, &p);
	data.wait();

	try {
		data.get();
	}
	catch (const std::exception& e) {
		std::cout << "exception : " << e.what() << '\n';
	}
	t.join();
}