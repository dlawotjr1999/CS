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
	join �Լ� : �ش� ��������� ������ �����ϸ� �����ϴ� �Լ�. ȣ�� �����尡 ������ ������ ���(blocking)
	detach �Լ� : Ư�� �����带 �и���Ű�� �Լ�. ������ ���� �� Ŀ���� �ڿ��� �ڵ� ȸ��(non-blocking)
	*/

	cout << "main function is terminated.\n";
}
