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
	// ios::app : ���� ��Ʈ�� �ڿ� ���� �����̱�
	// ios::ate : �ڵ����� ���� ���������� �б�� ���⸦ �ǽ�
	// ios::trunc : ���� ��Ʈ���� ���� ������ ������� ��� ������(default)
	// ios::in, ios::out : ���Ͽ� �Է��� �� ��, ����� �� ���� ����

	std::string s;
	if (out.is_open()) {
		out << "append";

		Human h("Ham", 20);
		out << h << std::endl;
	}

	return 0;
}