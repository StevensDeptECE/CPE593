#include <iostream>
using namespace std;

template<typename T>
class OrderedBinaryTree {
private:
	enum Color {RED, BLACK};
	class Node {
	public:
		T data;
		Node* left;
		Node* right;
		Node* parent;
		Color c;
		Node(const T& v, Node* L, Node* R, Node* P)
			: data(v), left(L), right(R), parent(P), c(RED) {}
		Node* grandparent() {
			if (parent == nullptr)
				return nullptr;
			return parent->parent;
		}
		Node* uncle() {
			Node* g = grandparent();
			if (g == nullptr)
				return nullptr;
			if (parent == g->left)
				return g->right;
			else
				return g->left;
		}
	};
	Node* root;
	void rotateLeft(Node* n) {
		Node *nnew = n->right;
    assert(nnew != nullptr); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n->right = nnew->left;
		nnew->left = n;
		nnew->parent = n->parent;
		n->parent = nnew;
	}
	
public:
	RBTree() : root(nullptr) {}
	void insertRepair(Node* n) {
		if (n->parent == nullptr)
			n->c = BLACK;
		else if (n->parent->c == BLACK)
			;
		else {
			Node* p = n->parent;
			Node* g = p->parent;
			Node* u = n->uncle();
			if (g == nullptr)
				return;
			if (u == nullptr)
				return;
			if (u->c == RED) {
				n->parent->c = BLACK;
				u->c = BLACK;
				g->c = RED;
				insertRepair(g);
			} else {
				if (n == g->left->right) {
					rotateLeft(p);
					n = n->left;
				} else if (n == g->right->left) {
					rotateRight(p);
					n = n->right; 
				}
				if (n == p->left)
					rotateRight(g);
				else
					rotateLeft(g);
				p->c = BLACK;
				g->c = RED;
			}
		}
	}
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
					insertRepair(p->left);
					return;
				}
				p = p->left;
			} else {
				if (p->right == nullptr) {
					p->right = new Node(v, nullptr, nullptr, p);
					insertRepair(p->right);
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
