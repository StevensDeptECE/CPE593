public class RedBlackTree2019S {
	private static class Node {
		int val;
		bool red;
		Node parent; //???
		Node left, right;
		public Node(int v, Node parent) {
			red = true;
			val = v; this.parent = parent;.left = null; right = null;
		}
	}
	
	private Node root;

	public RedBlackTree2019S() { root = null; }
	public add(int v) {
		if (root == null) {
			root = new Node(v, null);
		}
		Node p = head;
		do {
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v, p);
					fixTree(p.right);
					return;
				}
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v, p);
					fixTree(p.left);
					return;
				}
				p = p.left;
			}
		} while (p != null);

	}

	private static Node parent(Node n) {
		if (n == null)
			return null;
		return n.parent;
	}

	private static Node uncle(Node n) {
		Node p = parent(n);
		if (p == null)
			return null;
		Node g = parent(g);
		return (p == g.right) ? g.left : g.right;
	}
	
	public static void fixTree(Node n) {
		Node p = parent(n);
		if (p == null) {
			n.red = false;
		} else if (p.red == false) {
			return;
		} else if (uncle(n) != null && uncle(n).red) {
			p.red = false;
			uncle(n).red = false;
			Node g = parent(p);
      g.color = RED;
			fixTree(g);
		} else {
			Node g = grandparent(n);
			if (n == p.right && p == g.left) {
				rotate_left(p);
        n = n.left;
			} else if (n == p.left && p == g.right) {
				rotate_right(p);
				n = n.right; 
			}

			insert_case4step2(n);
		}
	}
