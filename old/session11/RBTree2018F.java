public class RBTree2018F {
	private static class Node {
		Node left, right;
		Node parent;
		int val;
		boolean red;
		Node(int v, Node parent, Node left, Node right) {
			val = v; this.parent = parent; this.left = left; this.right = right;
			red = true;
		}
	}
	private Node root;
	private static Node parent(Node n) {
		return n.parent;
	}

	private static Node grandparent(Node n) {
		if (n.parent == null)
			return null;
		return n.parent.parent;
	}
	private static Node uncle(Node n) {
		Node g = grandparent(n);
		if (g == null)
			return null;
		return g.left == parent(n) ? g.right : g.left;
	}
	
	private void rotateLeft(Node n) {
		Node nnew = n.right;
		Node p = parent(n);
		//		assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n.right = nnew.left; 
		nnew.left = n;
		n.parent = nnew;
		// handle other child/parent pointers
		if (n.right != null)
			n.right.parent = n;
		if (p != null) // initially n could be the root
		{
			if (n == p.left)
				p.left = nnew;
			else if (n == p.right) // if (...) is excessive
				p.right = nnew;
		}
		nnew.parent = p;
	}

	private void rotateRight(Node n) {
		Node nnew = n.left;
		Node p = parent(n);
		// assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
		n.left = nnew.right;
		nnew.right = n;
		n.parent = nnew;
 // handle other child/parent pointers
		if (n.left != null)
			n.left.parent = n;
		if (p != null) // initially n could be the root
		{
			if (n == p.left)
				p.left = nnew;
			else if (n == p.right) // if (...) is excessive
				p.right = nnew;
		}
		nnew.parent = p;
	}
	
	private void insertRepairTree(Node n) {
		if (parent(n) == null)
			n.red = false; // make root black
		else if (parent(n).red == false)
			return;
		else if (uncle(n).red) {
			parent(n).red = false;
			uncle(n).red = false;
			grandparent(n).red = true;
			insertRepairTree(grandparent(n));
		} else {
			Node p = parent(n);
			Node g = grandparent(n);

			if (n == g.left.right) {
				rotateLeft(p);
				n = n.left;
			} else if (n == g.right.left) {
				rotateRight(p);
				n = n.right; 
			}
			if (n == p.left)
				rotateRight(g);
			else
				rotateLeft(g);
			p.red = false;
			g.red = true;
		}
	}

	
	public RBTree2018F() {
		root = null;
	}

	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null, null);
			return;
		}
		Node p = root;
		while (true) {
			if (p.val > v) {
				if (p.left == null) {
					p.left = new Node(v, p, null, null);
					insertRepairTree(p.left);
					return;
				}
				p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, p, null, null);
					insertRepairTree(p.right);
					return;
				}
				p = p.right;
			}
				
		}
	}

}
