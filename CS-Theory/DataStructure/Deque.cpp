//#include <iostream>
//#include <cstdlib>
//
//#define MAX_QUEUE_SIZE 10
//
//template <class T>
//class DequeType {
//	int front, rear;
//	int size;
//	T* data;
//
//public:
//	DequeType() : front(0), rear(0), size(MAX_QUEUE_SIZE) {
//		data = new T[MAX_QUEUE_SIZE];
//	}
//	DequeType(int size_) : front(0), rear(0), size(size_) {
//		data = new T[size];
//	}
//	~DequeType() { delete[] data; }
//	
//	void error(std::string message);
//	bool isEmpty();
//	bool isFull();
//	int getSize() const;
//	void dequePrint();
//
//	void addRear(T item);
//	T deleteFront();
//	T getFront();
//	void addFront(T val);
//	T deleteRear();
//	T getRear();
//};
//
//template<class T>
//void DequeType<T>::error(std::string message) {
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//
//template<class T>
//bool DequeType<T>::isEmpty() {
//	return front == rear;
//}
//
//template<class T>
//bool DequeType<T>::isFull() {
//	return (rear + 1) % size == front;
//}
//
//template<class T>
//int DequeType<T>::getSize() const {
//	return size;
//}
//
//template<class T>
//void DequeType<T>::dequePrint() {
//	printf("DEQUE(front = %d rear = %d) = ", front, rear);
//	if (!isEmpty()) {
//		int i = front;
//		do {
//			i = (i + 1) % (size);
//			printf("%d | ", data[i]);
//			if (i == rear) break;
//		} while (i != front);
//	}
//	printf("\n");
//}
//
//template<class T>
//void DequeType<T>::addRear(T item) {
//	if (isFull())
//		error("Queue is full");
//	rear = (rear + 1) % size;
//	data[rear] = item;
//}
//
//template<class T>
//T DequeType<T>::deleteFront() {
//	if (isEmpty())
//		error("Queue is empty");
//	front = (front + 1) % size;
//	return data[front];
//}
//
//template<class T>
//T DequeType<T>::getFront() {
//	if (isEmpty())
//		error("Queue is empty");
//	return data[(front + 1) % size];
//}
//
//template<class T>
//void DequeType<T>::addFront(T val) {
//	if (isFull())
//		error("Queue is full");
//	data[front] = val;
//	front = (front - 1 + size) % size;
//}
//
//template<class T>
//T DequeType<T>::deleteRear() {
//	int prev = rear;
//
//	if (isEmpty())
//		error("Queue is empty");
//	rear = (rear - 1 + size) % size;
//	return data[prev];
//}
//
//template<class T>
//T DequeType<T>::getRear() {
//	if (isEmpty())
//		error("Queue is empty");
//	return data[rear];
//}
//
//int main() {
//	DequeType<int> q;
//
//	for (int i = 0; i < q.getSize(); i++) {
//		q.addFront(i);
//		q.dequePrint();
//	}
//	for (int i = 0; i < q.getSize(); i++) {
//		q.deleteRear();
//		q.dequePrint();
//	}
//	return 0;
//}