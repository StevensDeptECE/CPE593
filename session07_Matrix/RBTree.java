public class RBTree {
	private static class Node {
		int data;
		Node left, right, parent;
		enum Color { RED, BLACK};
		Color c;
		public Node(int v, Node L, Node R, Node P) {
			data = v; left = L; right = R; parent = P;
			c = RED;
		}
		public void print() {
			if (left != null)
				left.print();
			System.out.print(data);
			if (right != null)
				right.print();
		}
		public Node uncle() {
			if (parent == null || parent.parent == null)
				return null;

			if (parent.parent.left == parent) // if grandparent's left child
				return parent.parent.right;
			else
				return parent.parent.left;
		}
		public void repair() {
			if (parent == null) // case 1: you are now root
				c = BLACK;
			else if (this.parent.c == BLACK)
				return;
			else {
				Node g = parent.parent; // grandparent
				Node u = uncle();
				if (u != null) {
					if (u.c == RED) {
						parent.c = BLACK;
						u.c = BLACK;
						g.c = RED;
						g.repair():
					} else {  // case 4: uncle's color is BLACK
						if (this == parent.parent.left.right) {
							parent.rotateLeft();
							this = this.left;
						} else if (this == parent.parent.right.left) {
							parent.rotateRight();
							this = this.right; 
						}						
					}
				}
			}
		}

	}
	private Node root;
	public OrderedBinaryTree() { root = null; }
	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null, null);
			return;
		}
		Node p = root;
		while (true)
			if (v < p.data) {
				if (p.left == null) {
					p.left = new Node(v, null, null, p);
					repair();
					return;
				} else
					p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, null, null, p);
					repair();
					return;
				} else
					p = p.right;
			}
	}
		
  public void print() {
		root.print();
	}

  public static void main(String[] args) {
		OrderedBinaryTree t = new OrderedBinaryTree();
		t.add(3);
		t.add(1);
		t.add(4);
		t.add(1);
		t.add(5);
		t.add(9);
		t.add(2);
		t.print();
	}
}
