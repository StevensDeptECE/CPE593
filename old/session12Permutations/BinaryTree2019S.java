public class BinaryTree2019S {
	private static class Node {
		int val;
		Node parent; //???
		Node left, right;
		public Node(int v, Node parent) {
			val = v; this.parent = parent; left = null; right = null;
		}
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
	}
	
	private Node root;

	public BinaryTree2019S() { root = null; }
	public void add(int v) {
		if (root == null) {
			root = new Node(v, null);
		}
		Node p = root;
		do {
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v, p);
					return;
				}
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v, p);
					return;
				}
				p = p.left;
			}
		} while (p != null);

	}

	public void inorder() {
		if (root == null)
			return;
		root.inorder();
	}

	public void preorder() {
    if (root == null)
			return;
		root.preorder();
	}

	public void postorder() {
    if (root == null)
			return;
		root.postorder();
	}

	public static void main(String[] args) {
		BinaryTree2019S b = new BinaryTree2019S();
		b.add(3);
		b.add(1);
		b.add(4);
		b.add(1);
		b.add(5);
		System.out.println();
		b.inorder();
		System.out.println();
		b.preorder();
		System.out.println();
	}
}
