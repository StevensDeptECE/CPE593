public class BinaryTree2018F {
	private static class Node {
		int val;
		Node left, right;
		public Node(int v, Node L, Node R) { val = v; left = L; right = R; }

		public void inorder() {
			if (left != null)
				left.inorder();
			System.out.print(val);
			if (right != null)
				right.inorder();
		}

		public void preorder() {
			System.out.print(val);
			if (left != null)
				left.inorder();
			if (right != null)
				right.inorder();
		}

		public void postorder() {
			if (left != null)
				left.inorder();
			if (right != null)
				right.inorder();
			System.out.print(val);
		}

		public void add(int v) {
		if (this.val < v) {
			if (this.right != null)
					this.right.add(v);
				else {
					this.right = new Node(v, null, null);
					return;
				}
			} else {
				if (this.left != null)
					this.left.add(v);
				else {
					this.left = new Node(v, null, null);
					return;
				}
			}
		}
	}
	Node root;

	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null);
			return;
		}
		Node p = root;
		while (true)
			if (p.val > v) {
				if (p.left == null) {
					p.left = new Node(v, null, null);
					return;
				} else
					p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, null, null);
					return;
				} else
					p = p.right;
			}
	}
	public void addRecursive(int v) {
		if (root == null)
			root = new Node(v, null, null);
		else
			root.add(v);
	}

	public void remove(int v) {

	}

	public void inorder() {
		if (root == null)
			return;
		root.inorder();
		System.out.println();
	}
	public void preorder() {
		if (root == null)
			return;
		root.preorder();

		System.out.println();
	}
	public void postorder() {
		if (root == null)
			return;
		root.postorder();
		System.out.println();
	}
	
	public static void main(String[] args) {
		BinaryTree2018F t = new BinaryTree2018F();
		int d[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
		for (int x : d) {
			t.add(x);
		}
		t.inorder();
		t.preorder();
		t.postorder();
	}
}
