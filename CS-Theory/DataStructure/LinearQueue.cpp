//#include <iostream>
//#include <cstdlib>
//
//#define MAX_QUEUE_SIZE 100
//
//template<class T>
//class QueueType {
//
//private:
//	int front, rear;
//	int size;
//	T* data;
//
//public:
//	QueueType(int size_) : front(-1), rear(-1), size(size_) {
//		data = new T[size];
//	}
//	QueueType() : front(-1), rear(-1), size(MAX_QUEUE_SIZE) {
//		data = new T[MAX_QUEUE_SIZE];
//	}
//	~QueueType() { delete[] data; }
//
//	void error(std::string message) {
//		fprintf(stderr, "%n", message);
//		exit(1);
//	}
//	void queuePrint();
//	bool isFull();
//	bool isEmpty();
//	void enqueue(T item);
//	T dequeue();
//};
//
//template<class T>
//void QueueType<T>::queuePrint() {
//	for (int i = 0; i < size; i++) {
//		if (i <= front || i > rear)
//			std::cout << "  | ";
//		else printf("%d | ", data[i]);
//	}
//	printf("\n");
//}
//
//template<class T>
//bool QueueType<T>::isFull() {
//	if (rear == size - 1) return true;
//	else return false;
//}
//
//template<class T>
//bool QueueType<T>::isEmpty() {
//	if (front == rear) return true;
//	else return false;
//}
//
//template<class T>
//void QueueType<T>::enqueue(T item) {
//	if (isFull()) {
//		error("Queue is full");
//		return;
//	}
//	data[++rear] = item;
//}
//
//template<class T>
//T QueueType<T>::dequeue() {
//	if (isEmpty()) {
//		error("Queue is empty");
//		return -1;
//	}
//	T item = data[++front];
//	return item;
//}
//
//int main() {
//	int item = 0;
//	QueueType<int> q(10);
//
//	q.enqueue(10); q.queuePrint();
//	q.enqueue(20); q.queuePrint();
//	q.enqueue(30); q.queuePrint();
//
//	item = q.dequeue(); q.queuePrint();
//	item = q.dequeue(); q.queuePrint();
//	item = q.dequeue(); q.queuePrint();
//
//	return 0;
//}