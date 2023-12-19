//#pragma once
//#include <iostream>
//#include <cstdlib>
//
//template <typename T>
//struct node {
//	T data;
//	node<T>* left = nullptr;
//	node<T>* right = nullptr;
//
//	node(T _data, node<T>* _left = nullptr, node<T>* _right = nullptr) :
//		data(_data), left(_left), right(_right) {}
//};
//
//template <class T>
//class BinarySearchTree {
//private:
//	node<T>* root;
//
//	node<T>* insertNodeRec(node<T>* root, T value);
//	node<T>* deleteNodeRec(node<T>* root, T value);
//	node<T>* minValueNode(node<T>* root);
//
//public:
//	BinarySearchTree() : root(nullptr) {}
//
//	void insertNode(T data) { root = insertNodeRec(root, data); }
//	void deleteNode(T data) { root = deleteNodeRec(root, data); }
//	void inorder(node<T>* root);
//	void preorder(node<T>* root);
//	void postorder(node<T>* root);
//
//	int getNodeCount(node<T>* root);
//	int getLeafCount(node<T>* root);
//
//	node<T>* getRoot() const { return root; }
//};
//
//template <class T>
//node<T>* BinarySearchTree<T>::insertNodeRec(node<T>* root, T value) {
//	if (root == nullptr)
//		return new node<T>(value);
//	if (value < root->data)
//		root->left = insertNodeRec(root->left, value);
//	else if (value > root->data)
//		root->right = insertNodeRec(root->right, value);
//	return root;
//}
//
//template <class T>
//node<T>* BinarySearchTree<T>::deleteNodeRec(node<T>* root, T value) {
//	if (root == nullptr)
//		return root;
//	if (value < root->data)
//		root->left = deleteNodeRec(root->left, value);
//	else if (value > root->data)
//		root->right = deleteNodeRec(root->right, value);
//	else {
//		// 삭제할 노드를 찾음
//		// 자식이 없거나 하나인 경우
//		if (root->left == nullptr) {
//			node<T>* temp = root->right;
//			delete root;
//			return temp;
//		}
//		else if (root->right == nullptr) {
//			node<T>* temp = root->left;
//			delete root;
//			return temp;
//		}
//
//		// 두 개의 자식이 있는 경우
//		node<T>* temp = minValueNode(root->right);
//		root->data = temp->data;
//		root->right = deleteNodeRec(root->right, temp->data);
//	}
//	return root;
//}
//
//template <class T>
//node<T>* BinarySearchTree<T>::minValueNode(node<T>* root) {
//	node<T>* current = root;
//	while (current->left != nullptr) {
//		current = current->left;
//	}
//	return current;
//}
//
//template <class T>
//void BinarySearchTree<T>::inorder(node<T>* root) {
//	if (root) {
//		inorder(root->left);
//		std::cout << root->data << " ";
//		inorder(root->right);
//	}
//}
//
//template <class T>
//void BinarySearchTree<T>::preorder(node<T>* root) {
//	if (root) {
//		std::cout << root->data << " ";
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
//template <class T>
//void BinarySearchTree<T>::postorder(node<T>* root) {
//	if (root) {
//		postorder(root->left);
//		postorder(root->right);
//		std::cout << root->data << " ";
//	}
//}
//
//// ************************************************************************** //
//
//template <class T>
//int BinarySearchTree<T>::getNodeCount(node<T>* root) {
//	int count = 0;
//
//	if (root != nullptr) 
//		count = 1 + getNodeCount(root->left) + getNodeCount(root->right);
//	return count;
//}
//
//template <class T>
//int BinarySearchTree<T>::getLeafCount(node<T>* root) {
//	int count = 0;
//
//	if (root != nullptr) {
//		if (root->left == nullptr && root->right == nullptr)
//			return 1;
//		else
//			count = getLeafCount(node->left) + getLeafCount(node->right);
//	}
//	return count;
//}
//
//int main() {
//	BinarySearchTree<float> bst;
//	
//	bst.insertNode(10.0f);
//	bst.insertNode(11.0f);
//	bst.insertNode(10.5f);
//	bst.insertNode(9.0f);
//	bst.insertNode(9.5f);
//	bst.insertNode(11.5f);
//
//	std::cout << "preorder : ";
//	bst.preorder(bst.getRoot()); std::cout << '\n';
//	std::cout << "inorder : ";
//	bst.inorder(bst.getRoot()); std::cout << '\n';
//	std::cout << "postorder : ";
//	bst.postorder(bst.getRoot()); std::cout << '\n';
//}
