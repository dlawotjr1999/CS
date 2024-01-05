#include <iostream>
#include <string>

int main() {
	int t;
	
	while (true) {
		std::cin >> t;
		std::cout << "입력 : " << t << std::endl;
		// std::cin.setf(std::ios_base::hex, std::ios_base::basefield);	// 특정 서식 플래그를 설정하는 함수
		// std::cin >> hex >> t;
		if (std::cin.fail()) {
			std::cout << "숫자를 입력해주세요 : " << std::endl;
			std::cin.clear();	// flag 초기화
			std::cin.ignore(100, '\n');	// 개행문자가 나올 때까지 무시
		}
		if (t == 0) break;
	}
}