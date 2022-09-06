public class RBTree2019 {
	private static enum Color {RED, BLACK};
	private static class Node {
		int val;
		Node parent;
		Node left;
		Node right;
		Color c;
		public Node(int v, Node parent) {
			val = v;
			left = null;
			right = null;
			this.parent = parent;
			c = RED;
		}
		void inorder() {
			if (left != null)
				left.inorder();
			System.out.print(val);
			if (right != null)
				right.inorder();
		}
		void preorder() {
			System.out.print(val);
			if (left != null)
				left.preorder();
			if (right != null)
				right.preorder();
		}
		void postorder() {
			if (left != null)
				left.postorder();
			if (right != null)
				right.postorder();
			System.out.print(val);
		}

	}

	private Node root;

	public BinaryTree2019() {
		root = null;
	}

	// 3 1 5
	public void add(int v) {
		if (root == null) {
			root = new Node(v);
			return;
		}
		Node p = root;
		while(true)
			if (v < p.val) {
				if (p.left == null) {
					p.left = new Node(v);
					fixInsert(p.left);
					return;
				}
				p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v);
					fixInsert(p.right);
					return;
				}				
				p = p.right;
			}
	}

	public void inorder() {
		if (root != null)
			root.inorder();
	}

	public void preorder() {
		if (root != null)
			root.preorder();
	}


	public void postorder() {
		if (root != null)
			root.postorder();
	}

	private void fixInsert(Node n) {
		if (n.parent == null) {
			n.c = BLACK;
			return;
		}	else if (n.parent.c == BLACK)
			return;
		Node p = n.parent;
		Node g = p.parent;
		if (g != null)  {
			Node u = g.left == p ? g.right : g.left;
			if (u.c == RED) {
				u.c = BLACK;
				p.c = BLACK;
				g.c = RED;
				fixInsert(g);
			}
	}

	/*
		    3
      1   4  
     / 1 / 5


      1             2
       2    -->   1   3
         3

	 */
	public static void main(String[] args) {
		RBTree2019 t = new RBTree2019();

		t.add(3);
		t.add(1);
		t.add(4);
		t.add(1);
		t.add(5);
		t.inorder();
		System.out.println();
		t.preorder();
		System.out.println();
		t.postorder();
		System.out.println();
	}
	
}
