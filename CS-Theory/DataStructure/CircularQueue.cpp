#include <iostream>
#include <cstdlib>

#define MAX_QUEUE_SIZE 5

template<class T>
class QueueType {
private:
	int front, rear;
	int size;
	T* data;

public:
	QueueType(int size_) : front(0), rear(0), size(size_) {
		data = new T[size];
	}
	QueueType() : front(0), rear(0), size(MAX_QUEUE_SIZE) {
		data = new T[MAX_QUEUE_SIZE];
	}
  ~QueueType() { delete[] data; }

	void error(std::string message);
	bool isEmpty();
	bool isFull();
	void queuePrint();
	void enqueue(T item);
	T dequeue();
};

template<class T>
void QueueType<T>::error(std::string message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

template<class T>
bool QueueType<T>::isEmpty() {
	return front == rear;
}

template<class T>
bool QueueType<T>::isFull() {
	return (rear + 1) % size == front;
}

template<class T>
void QueueType<T>::queuePrint() {
	printf("QUEUE(front = %d rear = %d) = ", front, rear);
	if (!isEmpty()) {
		int i = front;
		do {
			i = (i + 1) % (size);
			printf("%d | ", data[i]);
			if (i == rear) break;
		} while (i != front);
	}
	printf("\n");
}

template<class T>
void QueueType<T>::enqueue(T item) {
	if (isFull())
		error("Queue is full");
	rear = (rear + 1) % size;
	data[rear] = item;
}

template<class T>
T QueueType<T>::dequeue() {
	if (isEmpty())
		error("Queue is empty");
	front = (front + 1) % size;
	return data[front];
}

int main() {
	QueueType<int> q(5);
	int item;

	while (!q.isFull()) {
		std::cin >> item;
		q.enqueue(item);
		q.queuePrint();
	}

	std::cout << '\n';
	std::cout << "Queue is full" << std::endl;
	std::cout << '\n';

	while (!q.isEmpty()) {
		item = q.dequeue();
		std::cout << item << " " << std::endl;
		q.queuePrint();
	}
	
	return 0;
}