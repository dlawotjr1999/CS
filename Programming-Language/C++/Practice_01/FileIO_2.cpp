#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Human {
	std::string name;
	int age;

public:
	Human(const std::string& name, int age) : name(name), age(age) {}
	std::string get_info() {
		return "Name : " + name + " / Age : " + std::to_string(age);
	}

	friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& o, Human& h) {
	o << h.get_info();
	return o;
}

// string -> number
double to_number(std::string s) {
	std::istringstream ss(s);
	double x;

	ss >> x;
	return x;
}

// number -> string
std::string to_str(int x) {
	std::ostringstream ss;
	ss << x;

	return ss.str();
}

int main() {
	std::ofstream out("test.txt", std::ios::app);
	// ios::app : 파일 스트림 뒤에 내용 덧붙이기
	// ios::ate : 자동으로 파일 끝에서부터 읽기와 쓰기를 실시
	// ios::trunc : 파일 스트림을 열면 기존의 내용들이 모두 지워짐(default)
	// ios::in, ios::out : 파일에 입력을 할 지, 출력을 할 지를 지정

	std::string s;
	if (out.is_open()) {
		out << "append";

		Human h("Ham", 20);
		out << h << std::endl;
	}

	return 0;
}