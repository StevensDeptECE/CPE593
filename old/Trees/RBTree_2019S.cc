class RBTree {
private:
	class Node {
	public:
		int val;
		enum Color{ RED, BLACK};
		Color c;
		Node* left;
		Node* right;
		Node* parent;
		Node(int v, Node* L, Node* R, Node* P) : val(v), left(L), right(R), parent(P), c(RED)
		{
		}
	};

	Node* root;

	Node* parent(Node* p) { return p->parent; }
	Node* grandparent(Node* n) {
		if (n->parent == nullptr)
			return nullptr;
		return n->parent->parent;
	}
	
public:
	RBTree() : root(nullptr) {}
	void add(int v) {
		Node* p = root;
		if (p == nullptr) {
			root = new Node(v, nullptr, nullptr, nullptr);
		} else {
			do {
				if (v > p->val) {
					if (p->right == nullptr) {
						p->right = new Node(v, nullptr, nullptr, p);
						fixUpTree(p->right);
						return;
					} else {
						p = p->right;
					}
				} else {
					if (p->left == nullptr) {
						p->left = new Node(v, nullptr, nullptr, p);
						fixUpTree(p->left);
						return;
					} else {
						p = p->left;
					}
				}

			} while (p != nullptr);
		}
	}

	void rotate_left(Node* n) {
		Node* nnew = n->right;
		Node* p = parent(n);
		//assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n->right = nnew->left; 
    nnew->left = n;
		n->parent = nnew;
		// handle other child/parent pointers
		if (n->right != nullptr)
			n->right->parent = n;
		if (p != nullptr) { // initially n could be the root
			if (n == p->left)
				p->left = nnew;
			else if (n == p->right) // if (...) is excessive
				p->right = nnew;
		}
		nnew->parent = p;
	}

	void rotate_right(Node* n) {
		Node* nnew = n->left;
		Node* p = parent(n);
		//		assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n->left = nnew->right;
		nnew->right = n;
		n->parent = nnew;
		// handle other child/parent pointers
		if (n->left != NULL)
			n->left->parent = n;
		if (p != NULL) // initially n could be the root
		{
			if (n == p->left)
				p->left = nnew;
			else if (n == p->right) // if (...) is excessive
				p->right = nnew;
		}
		nnew->parent = p;
	}
	
	
	void insertFixupTree(Node* n) {
		if (parent(n) == nullptr) {
			n->color = BLACK;
		} else if (parent(n)->color == BLACK) {
			return;
		} else if (uncle(n) != nullptr && uncle(n)->color == RED) {
			case3(n);
		} else {
			case4(n);
		}
	}
	void case3(struct node* n) {
		parent(n)->color = BLACK;
		uncle(n)->color = BLACK;
		Node* g = grandparent(n);
		g->color = RED;
		insertFixupTree(g);
	}
	void case4(struct node* n) {
		Node* p = parent(n);
		Node* g = grandparent(n);

		if (n == p->right && p == g->left) {
			rotate_left(p);
			n = n->left;
		} else if (n == p->left && p == g->right) {
			rotate_right(p);
			n = n->right; 
		}
		
		if (n == p->left)
			rotate_right(g);
		else
			rotate_left(g);
		p->color = BLACK;
		if(p != nullptr))
			g->color = RED;
	}
};
