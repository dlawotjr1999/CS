#include <iostream>
#include <string>

int main() {
	int t;
	
	while (true) {
		std::cin >> t;
		std::cout << "�Է� : " << t << std::endl;
		// std::cin.setf(std::ios_base::hex, std::ios_base::basefield);	// Ư�� ���� �÷��׸� �����ϴ� �Լ�
		// std::cin >> hex >> t;
		if (std::cin.fail()) {
			std::cout << "���ڸ� �Է����ּ��� : " << std::endl;
			std::cin.clear();	// flag �ʱ�ȭ
			std::cin.ignore(100, '\n');	// ���๮�ڰ� ���� ������ ����
		}
		if (t == 0) break;
	}
}