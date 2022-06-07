public class RBTree {
	private static class Node {
		private int val;
		private Node left, right, parent;
		private enum Color { RED, BLACK};
		Color color;
		public Node(int v, Node L, Node R) {
			val = v; left = L; right = R;
		}


		Node grandparent() {
			if (parent == null)
				return null;
			return parent.parent;
		}

		Node sibling() {
			if (parent == null)
				return null;
			if (parent.left == this)
				return parent.right;
			else
				return parent.left;
		}

		Node uncle() {
			Node g = grandparent();
			if (g == null)
				return null;
			return parent.sibling();
		}
			

		
	}
	private Node root;
	public RBTree() {
		root = null;
	}

	public void repair(Node n) {
    if (n.parent == null)
			insert_case1(n);
		else if (n.parent.color == Color.BLACK) {
		} else if (n.uncle().color == Color.RED) {
			insert_case3(n);
		} else {
			insert_case4(n);
		}
	}

	private void insert_case1(Node n) {
		if (n.parent == null)
			n.color = Color.BLACK;
	}

	private void insert_case3(Node n) {
		n.parent.color = Color.BLACK;
		n.uncle().color = Color.BLACK;
		Node g = n.grandparent();
		g.color = Color.RED;
    repair(g);
	}

	private void insert_case4(Node n) {
		Node p = n.parent;
		Node g = n.grandparent();

		if (n == g.left.right) {
			rotate_left(p);
			n = n.left;
		} else if (n == g.right.left) {
			rotate_right(p);
			n = n.right; 
		}
		insert_case4step2(n);
	}

	private void insert_case4b(Node n) {
		Node p = n.parent();
		Node g = n.grandparent();

		if (n == p.left)
			rotate_right(g);
		else
			rotate_left(g);
		p.color = Color.BLACK;
		g.color = Color.RED;
	}

	private void rotate_left(Node n) {
		Node nnew = n.right;
		assert(nnew != null); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n.right = nnew.left;
		n.right.parent = n; // our right child's new parent is US!
		nnew.left = n;
		nnew.parent = n.parent;
		n.parent = nnew; // nnew is now our parent
		// (the other related parent and child links would also have to be updated)
	}

	private void rotate_right(Node n) {
		Node nnew = n.left;
		assert(nnew != null); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n.left = nnew.right;
		nnew.right = n;
		nnew.parent = n.parent;
		n.parent = nnew;
		// (the other related parent and child links would also have to be updated)
	}
	

	void add(int v) {
		if (root == null) {
			root = new Node(v, null, null);
			return;
		}
		Node p = root;
		while (true) {
			if (p.val > v) {
				if (p.left == null){
					p.left = new Node(v, null, null);
					repair(p.left);
					return;
				}
				p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, null, null);
					repair(p.right);
					return;
				}
				p = p.right;
			}
		}
	}

	public void inorder() { root.inorder(); }
	public void preorder() { root.preorder(); }
	public void postorder() { root.postorder(); }

}
