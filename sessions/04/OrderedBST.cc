class OrderedBST {
private:
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node(int v) : val(v), left(nullptr), right(nullptr) {}
	};
	Node* root;
public:
	OrderedBST() : root(nullptr) {}
  void add(int v) {
		if (root == nullptr) {
			root = new Node(v);
			return; // GET OUT!!!
		}
		Node* p = root;
		while (true) { // O(log n)
			if (v > p->val) { // going to the right
				if (p->right == nullptr) {
					p->right = new Node(v);
					return;
				}
				p=p->right;
			} else {
				if (p->left == nullptr) {
					p->left = new Node(v);
					return;
				}
				p=p->left;
			}
		}
	}
};

int main() {
	constexpr int n = 10;
	OrderedBST tree;
	for (int i = 0; i < n; i++)
		tree.add(i);
}
