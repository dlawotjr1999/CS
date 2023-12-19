#include <iostream>
#include <cstdlib>

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void insertNode(T value);
    void deleteNode(T value);
    void clearList();
    void displayList();
    void reverseDisplay();
    Node<T>* findNode(T value);
};

template <class T>
void DoubleLinkedList<T>::insertNode(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void DoubleLinkedList<T>::deleteNode(T value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
    std::cout << "Node with value " << value << " not found." << std::endl;
}

template <class T>
void DoubleLinkedList<T>::clearList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

template <class T>
void DoubleLinkedList<T>::displayList() {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <class T>
void DoubleLinkedList<T>::reverseDisplay() {
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << '\n';
}

template <class T>
Node<T>* DoubleLinkedList<T>::findNode(T value) {
    Node<T>* current = head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

int main() {
    DoubleLinkedList<int> dll;

    // 노드 삽입
    dll.insertNode(1);
    dll.insertNode(2);
    dll.insertNode(3);

    // 현재 리스트 출력
    std::cout << "Original List: ";
    dll.displayList();

    // 노드 삭제
    dll.deleteNode(2);

    // 삭제 후 리스트 출력
    std::cout << "List after deletion: ";
    dll.displayList();

    std::cout << "After clear List: ";
    dll.clearList();

    return 0;
}
