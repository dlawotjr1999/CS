#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream in1("test.txt"); // ���� �б� �غ�
	std::ifstream in2("test.txt", std::ios::binary); // �������� �б�
	std::ifstream in3("test2.txt");
	
	std::string s1;
	std::string s2;
	int x;

	if (in1.is_open()) {
		in1 >> s1;
		std::cout << "�Է� ���� ���ڿ� : " << std::endl;
	}
	else {
		std::cout << "������ ã�� �� �����ϴ�" << std::endl;
	}
	in1.close();

	if (in2.is_open()) {
		in2.read((char*)(&x), 4);
		std::cout << std::hex << x << std::endl;
	}
	else {
		std::cout << "������ ã�� �� �����ϴ�" << std::endl;
	}
	in2.close();

	if (in3.is_open()) {
		in3.seekg(0, std::ios::end);	// descriptor�� ���� ������ �ű��
		int size = in3.tellg();		// �׸��� �� ��ġ�� �д´�(������ ũ��)
		s2.resize(size);		// �� ũ���� ���ڿ��� �Ҵ��Ѵ�
		in3.seekg(0, std::ios::beg); // descriptor�� �ٽ� ���� �� ������ �ű��
		in3.read(&s2[0], size);		// ���� ��ü ������ �о ���ڿ��� �����Ѵ�
		std::cout << s2 << std::endl;
	}
	else {
		std::cout << "������ ã�� �� �����ϴ�" << std::endl;
	}

	return 0;
}