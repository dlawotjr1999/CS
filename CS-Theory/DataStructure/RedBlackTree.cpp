//#include <iostream>
//#include <memory>
//
//enum Color { RED, BLACK };
//
//template<typename T>
//struct Node {
//	T key;
//	Color color;
//	Node<T>* parent;
//	Node<T>* left;
//	Node<T>* right;
//
//	Node(T k) : key(k), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
//};
//
//template<class T>
//class RedBlackTree {
//private:
//	Node<T>* root;
//
//	void leftRotate(Node<T>* x) {
//		Node<T>* y = x->right;
//		x->right = y->left;
//		if (y->left != nullptr)
//			y->left->parent = x;
//		y->parent = x->parent;
//		if (x->parent == nullptr)
//			root = y;
//		else if (x == x->parent->left)
//			x->parent->left = y;
//		else
//			x->parent->right = y;
//		y->left = x;
//		x->parent = y;
//	}
//	void rightRotate(Node<T>* y) {
//		Node<T>* x = y->left;
//		y->left = x->right;
//		if (x->right != nullptr) {
//			x->right->parent = y;
//		}
//		x->parent = y->parent;
//		if (y->parent == nullptr) {
//			root = x;
//		}
//		else if (y == y->parent->left) {
//			y->parent->left = x;
//		}
//		else {
//			y->parent->right = x;
//		}
//		x->right = y;
//		y->parent = x;
//	}
//	void insertFixup(Node<T>* z) {
//		while (z->parent != nullptr && z->parent->color == RED) {
//			if (z->parent == z->parent->parent->left) {
//				Node<T>* y = z->parent->parent->right;
//				if (y != nullptr && y->color == RED) {
//					z->parent->color = BLACK;
//					y->color = BLACK;
//					z->parent->parent->color = RED;
//					z = z->parent->parent;
//				}
//				else {
//					if (z == z->parent->right) {
//						z = z->parent;
//						leftRotate(z);
//					}
//					z->parent->color = BLACK;
//					z->parent->parent->color = RED;
//					rightRotate(z->parent->parent);
//				}
//			}
//			else {
//				Node<T>* y = z->parent->parent->left;
//				if (y != nullptr && y->color == RED) {
//					z->parent->color = BLACK;
//					y->color = BLACK;
//					z->parent->parent->color = RED;
//					z = z->parent->parent;
//				}
//				else {
//					if (z == z->parent->left) {
//						z = z->parent;
//						rightRotate(z);
//					}
//					z->parent->color = BLACK;
//					z->parent->parent->color = RED;
//					leftRotate(z->parent->parent);
//				}
//			}
//		}
//		root->color = BLACK;
//	}
//	void transplant(Node<T>* u, Node<T>* v) {
//		if (u->parent == nullptr) 
//			root = v;
//		else if (u == u->parent->left) 
//			u->parent->left = v;
//		else 
//			u->parent->right = v;
//		if (v != nullptr) 
//			v->parent = u->parent;
//	}
//	void deleteFixup(Node<T>* x) {
//		while (x != root && (x == nullptr || x->color == BLACK)) {
//			if (x == x->parent->left) {
//				Node<T>* w = x->parent->right;
//				if (w->color == RED) {
//					w->color = BLACK;
//					x->parent->color = RED;
//					leftRotate(x->parent);
//					w = x->parent->right;
//				}
//				if ((w->left == nullptr || w->left->color == BLACK) &&
//					(w->right == nullptr || w->right->color == BLACK)) {
//					w->color = RED;
//					x = x->parent;
//				}
//				else {
//					if (w->right == nullptr || w->right->color == BLACK) {
//						if (w->left != nullptr) {
//							w->left->color = BLACK;
//						}
//						w->color = RED;
//						rightRotate(w);
//						w = x->parent->right;
//					}
//					w->color = x->parent->color;
//					x->parent->color = BLACK;
//					if (w->right != nullptr) {
//						w->right->color = BLACK;
//					}
//					leftRotate(x->parent);
//					x = root;
//				}
//			}
//			else {
//				Node<T>* w = x->parent->left;
//				if (w->color == RED) {
//					w->color = BLACK;
//					x->parent->color = RED;
//					rightRotate(x->parent);
//					w = x->parent->left;
//				}
//				if ((w->right == nullptr || w->right->color == BLACK) &&
//					(w->left == nullptr || w->left->color == BLACK)) {
//					w->color = RED;
//					x = x->parent;
//				}
//				else {
//					if (w->left == nullptr || w->left->color == BLACK) {
//						if (w->right != nullptr) {
//							w->right->color = BLACK;
//						}
//						w->color = RED;
//						leftRotate(w);
//						w = x->parent->left;
//					}
//					w->color = x->parent->color;
//					x->parent->color = BLACK;
//					if (w->left != nullptr) {
//						w->left->color = BLACK;
//					}
//					rightRotate(x->parent);
//					x = root;
//				}
//			}
//		}
//		if (x != nullptr) {
//			x->color = BLACK;
//		}
//	}
//
//public:
//	RedBlackTree() : root(nullptr) {}
//
//	void insert(T key);
//	void remove(T key);
//	void inorder(Node<T>* x);
//	Node<T>* search(T key);
//	Node<T>* getRoot() const { return root; }
//};
//
//template <class T>
//void RedBlackTree<T>::insert(T key) {
//	Node<T>* z = new Node<T>(key);
//	Node<T>* y = nullptr;
//	Node<T>* x = root;
//
//	while (x != nullptr) {
//		y = x;
//		if (z->key < x->key)
//			x = x->left;
//		else
//			x = x->right;
//	}
//	z->parent = y;
//	if (y == nullptr)
//		root = z;
//	else if (z->key < y->key)
//		y->left = z;
//	else
//		y->right = z;
//
//	insertFixup(z);
//}
//
//template <class T>
//void RedBlackTree<T>::remove(T key) {
//	Node<T>* z = search(key);
//	if (z == nullptr)
//		return;
//
//	Node<T>* y = z;
//	Node<T>* x;
//	Color yOriginalColor = y->color;
//
//	if (z->left == nullptr) {
//		x = z->right;
//		transplant(z, z->right);
//	}
//	else if (z->right == nullptr) {
//		x = z->left;
//		transplant(z, z->left);
//	}
//	else {
//		y = z->right;
//		while (y->left != nullptr)
//			y = y->left;
//		yOriginalColor = y->color;
//		x = y->right;
//		if (y->parent == z) {
//			if (x != nullptr)
//				x->parent = y;
//		}
//		else {
//			transplant(y, y->right);
//			y->right = z->right;
//			if (y->right != nullptr)
//				y->right->parent = y;
//		}
//		transplant(z, y);
//		y->left = z->left;
//		if (y->left != nullptr)
//			y->left->parent = y;
//		y->color = z->color;
//		}
//	delete z;
//
//	if (yOriginalColor == BLACK)
//		deleteFixup(x);
//}
//
//template <class T>
//void RedBlackTree<T>::inorder(Node<T>* root) {
//	if (root != nullptr) {
//		inorder(root->left);
//		std::cout << root->key << " ";
//		inorder(root->right);
//	}
//}
//
//template <class T>
//Node<T>* RedBlackTree<T>::search(T key) {
//	Node<T>* current = root;
//	while (current != nullptr) {
//		if (key == current->key)
//			return current;
//		else if (key < current->key)
//			current = current->left;
//		else
//			current = current->right;
//	}
//	return nullptr;
//}
//
//int main() {
//	RedBlackTree<int> tree;
//
//	tree.insert(10);
//	tree.insert(30);
//	tree.insert(20);
//	tree.insert(25);
//	tree.insert(15);
//
//	tree.inorder(tree.getRoot());
//	std::cout << '\n';
//
//	tree.remove(20);
//
//	tree.inorder(tree.getRoot());
//
//	return 0;
//}