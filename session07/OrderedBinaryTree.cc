#include <iostream>
using namespace std;

template<typename T>
class OrderedBinaryTree {
private:
	class Node {
	public:
		T data;
		Node* left;
		Node* right;
		Node* parent;
		Node(const T& v, Node* L, Node* R, Node* P)
			: data(v), left(L), right(R), parent(P) {}
		void inorder() {
			if (left != nullptr)
				left->inorder();
			cout << data << ' ';
			if (right != nullptr)
				right->inorder();
		}
		void preorder() {
			cout << data << ' ';
			if (left != nullptr)
				left->preorder();
			if (right != nullptr)
				right->preorder();
		}
		void postorder() {
			if (left != nullptr)
				left->postorder();
			if (right != nullptr)
				right->postorder();
			cout << data << ' ';
		}
	};
	Node* root;
public:
	OrderedBinaryTree() : root(nullptr) {}
	void add(const T& v) {
		if (root == nullptr) {
			root = new Node(v, nullptr, nullptr, nullptr);
			return;
		}
		Node* p = root;
		while (true)
			if (v < p->data) {
				if (p->left == nullptr) {
					p->left = new Node(v, nullptr, nullptr, p);
					return;
				}
				p = p->left;
			} else {
				if (p->right == nullptr) {
					p->right = new Node(v, nullptr, nullptr, p);
				return;
				}
				p = p->right;
			}
	}
	void inorder() {
		if (root != nullptr)
			root->inorder();
	}
	void preorder() {
		if (root != nullptr)
			root->preorder();
	}
	void postorder() {
		if (root != nullptr)
			root->postorder();
	}

};

/**
              3
             / \
            1   4
             \   \
              1   5
               \   \
                2   9


 */

int main() {
	OrderedBinaryTree<int> t;
	t.add(3);
	t.add(1);
	t.add(4);
	t.add(1);
	t.add(5);
	t.add(9);
	t.add(2);
	t.inorder();  cout << '\n';
	t.preorder();  cout << '\n';
	t.postorder();  cout << '\n';
}
