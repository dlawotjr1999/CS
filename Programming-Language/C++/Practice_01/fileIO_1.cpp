#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream in1("test.txt"); // 파일 읽기 준비
	std::ifstream in2("test.txt", std::ios::binary); // 이진수로 읽기
	std::ifstream in3("test2.txt");
	
	std::string s1;
	std::string s2;
	int x;

	if (in1.is_open()) {
		in1 >> s1;
		std::cout << "입력 받은 문자열 : " << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다" << std::endl;
	}
	in1.close();

	if (in2.is_open()) {
		in2.read((char*)(&x), 4);
		std::cout << std::hex << x << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다" << std::endl;
	}
	in2.close();

	if (in3.is_open()) {
		in3.seekg(0, std::ios::end);	// descriptor를 파일 끝으로 옮긴다
		int size = in3.tellg();		// 그리고 그 위치를 읽는다(파일의 크기)
		s2.resize(size);		// 그 크기의 문자열을 할당한다
		in3.seekg(0, std::ios::beg); // descriptor를 다시 파일 맨 앞으로 옮긴다
		in3.read(&s2[0], size);		// 파일 전체 내용을 읽어서 문자열에 저장한다
		std::cout << s2 << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다" << std::endl;
	}

	return 0;
}