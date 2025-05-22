#include <iostream>
#include <thread>

using namespace std;

void func1() {
	for (int i = 0; i < 10; i++)
		std::cout << "Therad1...\n";
}

void func2() {
	for (int i = 0; i < 10; i++)
		std::cout << "Therad2...\n";
}

void func3() {
	for (int i = 0; i < 10; i++)
		std::cout << "Therad3...\n";
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	//t1.join();
	//t2.join();
	//t3.join();

	t1.detach();
	t2.detach();
	t3.detach();

	/*
	join 함수 : 해당 쓰레드들이 실행을 종료하면 리턴하는 함수. 호출 스레드가 종료할 때까지 대기(blocking)
	detach 함수 : 특정 쓰레드를 분리시키는 함수. 쓰레드 종료 시 커널이 자원을 자동 회수(non-blocking)
	*/

	cout << "main function is terminated.\n";
}
