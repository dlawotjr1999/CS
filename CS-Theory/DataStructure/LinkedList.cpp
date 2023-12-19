//#include <iostream>
//#include <cstdlib>
//
//template <typename T>
//struct node {
//	T data;
//	node<T>* nextNode;
//};
//
//template <class T>
//class LinkedList {
//private:
//	node<T>* head;
//	node<T>* tail;
//
//public:
//	LinkedList() : head(nullptr), tail(nullptr) {}
//	~LinkedList() {}
//
//	node<T>* getHead() const { return head; }
//	node<T>* reverse();
//	int findData(T data);
//	void addFrontNode(T data);
//	void addNode(T data);
//	void insertNode(node<T>* prevNode, T data);
//	void deleteNode(node<T>* prevNode);
//	void printNode(node<T>* head);
//};
//
//// 첫 번째의 node 추가
//template <class T>
//void LinkedList<T>::addFrontNode(T data) {
//	node<T>* temp = new node<T>;
//	temp->data = data;
//
//	if (head == nullptr) {
//		head = temp;
//		tail = temp;
//	}
//	else {
//		temp->nextNode = head;
//		head = temp;
//	}
//}
//
//// 마지막의 node 추가
//template <class T>
//void LinkedList<T>::addNode(T data) {
//	node<T>* temp = new node<T>;
//
//	temp->data = data;
//	temp->nextNode = nullptr;
//
//	if (head == nullptr) {
//		head = temp;
//		tail = temp;
//	}
//	else {
//		tail->nextNode = temp;
//		tail = temp;
//	}
//}
//
//template <class T>
//void LinkedList<T>::insertNode(node<T>* prevNode, T data) {
//	node<T>* temp = new node<T>;
//	temp->data = data;
//
//	temp->nextNode = prevNode->nextNode;
//	prevNode->nextNode = temp;
//}
//
//template <class T>
//void LinkedList<T>::deleteNode(node<T>* prevNode) {
//	node<T>* temp = prevNode->nextNode;
//	prevNode->nextNode = temp->nextNode;
//
//	delete temp;
//}
//
//template <class T>
//void LinkedList<T>::printNode(node<T>* head) {
//	if (head == nullptr) std::cout << "\n";
//	else {
//		std::cout << head->data << " ";
//		printNode(head->nextNode);
//	}
//}
//
//template <class T>
//int LinkedList<T>::findData(T data) {
//	node<T>* node = head;
//	int index = 0;
//
//	while (node != nullptr) {
//		if (node->data == data) return index;
//		node = node->nextNode;
//		index++;
//	}
//	return -1;
//}
//
//template <class T>
//node<T>* LinkedList<T>::reverse() {
//	node<T>* p, * q, * r;
//
//	p = head;
//	q = nullptr;
//	while (p != nullptr) {
//		r = q;
//		q = p;
//		p = p->nextNode;
//		q->nextNode = r;
//	}
//	return q;
//}
//
//int main() {
//	LinkedList<int> list;
//
//	list.addNode(1);
//	list.addNode(2);
//	list.addNode(3);
//	list.addFrontNode(0);
//	list.printNode(list.getHead());
//}