#include <iostream>
#include <string>
#include <map>
using namespace std;

class BinaryTree {
private:
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int v) : val(v), left(nullptr), right(nullptr) {}

		void inorder() {
			if (left != nullptr)
				left->inorder();
			cout << val << ' ';
			if (right != nullptr)
				right->inorder();
		}
		void preorder() {
			cout << val << ' ';
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
			cout << val << ' ';
		}

	};
	Node* root;
public:
	BinaryTree() : root(nullptr) {}
	void add(int v) {
		if (root == nullptr) {
			root = new Node(v);
			return;
		}
		Node* p = root;
		while (true) {
			if (v < p->val) {
				if (p->left == nullptr) {
					p->left = new Node(v);
					return;
				}
				p = p->left;
			}	else {
				if (p->right == nullptr) {
					p->right = new Node(v);
					return;
				}
				p = p->right;
			}
		}
			
	}

	void inorder() const {
		if (root != nullptr)
			root->inorder();
	}
	void preorder() const {
		if (root != nullptr)
			root->preorder();
	}
	void postorder() const {
		if (root != nullptr)
			root->postorder();
	}

};

int main() {
	map<string, int> price;

	price["XOM"] = 92;
	price["AAPL"] = 213;
	price["IBM"] = 102;
	price["BIDU"] = 186;

	for (auto x : price) {
		cout << x.first << "==>" << x.second << "\n";
	}

	/*
		                       3
													/  \
												 /    \
												1      4
                         \      \
												  1      5
                                  \
                                   9

	 */
	BinaryTree b;
	b.add(3);
	b.add(1);
	b.add(4);
	b.add(1);
	b.add(5);
	b.add(9);
	b.inorder();  /  1 1 3 4 5 9
	cout << "\n\n";
	b.preorder(); // 3 1 1 4 5 9
	cout << "\n\n";
	b.postorder(); // 1 1 9 5 4 3
}
	
