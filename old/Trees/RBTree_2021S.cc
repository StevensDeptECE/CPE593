class RBTree {
private:
	enum class Color {BLACK, RED};
	class Node { // RBTree::Node
	public:
		int val;
		Color c;
		Node* parent;
		Node* left;
		Node* right;
		Node(int v, Node* p) : val(v), parent(p),
													 left(nullptr), right(nullptr), c(Color::RED) {}

		Node* add(int v) {
			if (v < val) {
				if (left == nullptr) {
					return left = new Node(v, this);
				}
				left->add(v);
			} else {
				if (right == nullptr) {
					return right = new Node(v, this);
				}
				right->add(v);
			}
		}
	};
	Node* head;

	Node* iterativeAdd(int v) {
		if (head == nullptr) {
			return head = new Node(val, nullptr);
		}
		Node* p = head;

		while (true) {
			if (v < p->val) {
				if (p->left == nullptr) {
					return p->left = new Node(v, p);
				}
				p = p->left;
			} else {
				if (p->right == nullptr) {
					return p->right = new Node(v, p);
				}
				p = p->right;			
			}
		}
	}
	
	Node* recursiveAdd(int v) {
		if (head == nullptr) {
			return head = new Node(val, nullptr);
		}
		return root->add(v);
	}

public:
	RBTree() : head(nullptr) {}
	void add(int v) {
		Node* p = iterativeAdd(v);
		recursiveInsertRepair(p);
	}
	void resursiveInsertRepair(Node* n) {
		Node* parent = n->parent;

		//case 1: root
		if (parent == nullptr) {
			n->color = Color::BLACK;
			return;
		}

		//case 2: your parent is black, no color violation
		if (parent->color == Color::BLACK)
			return;
		
		Node* g = parent->parent;
		if (g == nullptr)
			return;
		// we definitely have a grandparent, do we have an uncle?
		Node* uncle = g->left == parent ? g->right : g->left;
		if (uncle == nullptr)
			return;

		//case 3: your parent and your uncle are both red
		if (uncle->color == Color::RED) {
			uncle->color = Color::BLACK;
			parent->color = Color::BLACK;
			g->color = Color::RED;
			recursiveInsertRepair(g);
			return;
		}

		// case 4: only your parent is red
		if (parent->right == n) {
			if (g->left == parent) {
				rotateLeft(n);
				n = n->left;
			} else {
				
			}
		} else { // your parent is grandparent's LEFT child
			if (g->left == parent) {

			} else {
				
			}
		}
		
