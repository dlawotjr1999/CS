#include <iostream>
#include <atomic>
#include <thread>

// memory_order_seq_cst : 메모리 명령의 순차적 일관성(sequential consistency)를 보장함
// memory_order를 지정하지 않으면 디폴트로 memory_order_seq_cst가 지정됨

std::atomic<bool> x(false);
std::atomic<bool> y(false);
std::atomic<int> z(0);

void write_x() { x.store(true, std::memory_order_seq_cst); }

void write_y() { y.store(true, std::memory_order_seq_cst); }

void read_x_then_y() {
	while (!x.load(std::memory_order_seq_cst));
	if (y.load(std::memory_order_seq_cst)) {
		++z;
	}
}

void read_y_then_x() {
	while (!y.load(std::memory_order_seq_cst));
	if (x.load(std::memory_order_seq_cst)) {
		++z;
	}
}

int main() {
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);

	a.join();
	b.join();
	c.join();
	d.join();

	std::cout << "z : " << z;
}