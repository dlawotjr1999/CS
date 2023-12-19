//#include <iostream>
//#include <cstdlib>
//
//#define MAX_STACK_SIZE 100
//
//template<class T>
//class StackType {
//private:
//	int size;
//	int top;
//	T* data;
//
//public:
//	StackType(int size_) : size(size_), top(-1) { data = new T[size]; }
//	StackType() : size(MAX_STACK_SIZE), top(-1) { data = new T[MAX_STACK_SIZE]; }
//	~StackType() { delete[] data; };
//
//	bool isEmpty();
//	bool isFull();
//	void push(T item);
//	T pop();
//};
//
//template<class T>
//bool StackType<T>::isEmpty() { return top == -1; }
//
//template<class T>
//bool StackType<T>::isFull() { return top == (size - 1); }
//
//template<class T>
//void StackType<T>::push(T item) {
//	if (isFull()) {
//		fprintf(stderr, "Stack Overflow");
//		return;
//	}
//	else data[++top] = item;
//}
//
//template<class T>
//T StackType<T>::pop() {
//	if (isEmpty()) {
//		fprintf(stderr, "Stack Underflow");
//		exit(1);
//	}
//	else return data[top--];
//}
//
//int main() {
//	StackType<int> s1(10);
//	StackType<std::string> s2;
//
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//	std::cout << s1.pop() << std::endl;
//	std::cout << s1.pop() << std::endl;
//	std::cout << s1.pop() << std::endl;
//
//	s2.push("violin");
//	s2.push("viola");
//	s2.push("cello");
//	s2.push("contrabass");
//	std::cout << s2.pop() << std::endl;
//	std::cout << s2.pop() << std::endl;
//	std::cout << s2.pop() << std::endl;
//	std::cout << s2.pop() << std::endl;
//
//	return 0;
//}