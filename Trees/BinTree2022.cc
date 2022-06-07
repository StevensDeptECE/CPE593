#include <iostream>
using namespace std;

class BinTree {
private:
  class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int v, Node* left, Node* right)
			: val(v), left(left), right(right) {}
		void inorder() {
			if (left != nullptr)
				left->inorder();
			cout << val;
			if (right != nullptr)
				right->inorder();
		}
		void preorder() {
			cout << val;
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
			cout << val;
  	}

	};

	Node* root;
public:

	BinTree() : root (nullptr) {}
	void add(int v) {
		if (root == nullptr) {
			root = new Node(v, nullptr, nullptr);
			return;
		}
    Node* p = root;

		while (true) {
			if (v > p->val) {
				if (p->right != nullptr) {
					p = p->right;
				} else {
					p->right = new Node(v, nullptr, nullptr);
					return;
				}
			} else {
				if (p->left != nullptr) {
					p = p->left;
				} else {
					p->left = new Node(v, nullptr, nullptr);
					return;
				}
			}
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

/*
	             3
             1   5
              2 4  

 */
int main() {
	BinTree t;
	t.add(3);
	t.add(1);
	t.add(5);
	t.add(4);
	t.add(2);
	t.inorder(); // 12345
	cout << '\n';
	t.preorder(); // 31254
	cout << '\n';
	t.postorder();
	cout << '\n';
}
