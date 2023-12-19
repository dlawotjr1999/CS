#include <iostream>

#define MAX_SIZE 1000

template <class T>
class PriorityQueue {
private:
	T* heap;
	int heapsize;

public:
	PriorityQueue() { heap = new T[MAX_SIZE]; heapsize = 0; }
	~PriorityQueue() { delete[] heap; }

	void insertMaxHeap(T item) {
		int i;
		i = ++(heapsize);

		while ((i != 1) && (item > heap[i / 2])) {
			heap[i] = heap[i / 2];
			i /= 2;
		}
		heap[i] = item;
	}
	T deleteMaxHeap() {
		int parent = 1, child = 2;
		T item, temp;

		item = heap[1];
		temp = heap[(heapsize)--];
		while (child <= heapsize) {
			if ((child < heapsize) && (heap[child] < heap[child + 1]))
				child++;
			if (temp >= heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		return item;
	}
};

int main() {
	PriorityQueue<unsigned short> maxheap;

	unsigned short d1, d2, d3;

	maxheap.insertMaxHeap(10);
	maxheap.insertMaxHeap(5);
	maxheap.insertMaxHeap(30);

	d1 = maxheap.deleteMaxHeap();
	std::cout << d1 << ' ';
	d2 = maxheap.deleteMaxHeap();
	std::cout << d2 << ' ';
	d3 = maxheap.deleteMaxHeap();
	std::cout << d3 << ' ';

	return 0;
}