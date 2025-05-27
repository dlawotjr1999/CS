#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; itr++) {
		sum += *itr;
	}
	*result = sum;

	// �������� id�� ����
	thread::id this_id = this_thread::get_id();

	// std::cout ��� printf�� ����ϴ� ����
	// printf �Լ��� context-switching�� �߻��ϴ��� �ٸ� ��������� �� ���̿� �޼����� ������� ���ϰ� �ϱ� ����
	printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start, *(end - 1), sum);
}

int main() {
	vector<int> vec(100000);
	for (int i = 0; i < 100000; i++) {
		vec[i] = i + 1;
	}

	// �� ������鿡�� ���� ���� �����ϴ� ����
	vector<int> partial_sums(4);

	// �����忡 ���ڸ� �����Ϸ��� std::bind�� �����ϰ� ����ϸ� ��. �� ù ��° ���ڷδ� �Լ���, ���Ŀ��� �� �Լ��� parameter�� ����.
	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.emplace_back(thread(worker, vec.begin() + i * 2500, vec.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i = 0; i < 4; i++)
		workers[i].join();

	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	std::cout << "��ü �� : " << total << std::endl;
}