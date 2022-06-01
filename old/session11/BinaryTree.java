public class BinaryTree {
	private static class Node {
		private int val;
		private Node left, right;
		public Node(int v, Node L, Node R) {
			val = v; left = L; right = R;
		}
		public void inorder() {
			if (left != null)
				left.inorder();
			System.out.println(val);
			if (right != null)
				right.inorder();
		}
		public void preorder() {
			System.out.println(val);
			if (left != null)
				left.preorder();
			if (right != null)
				right.preorder();
		}
		public void postorder() {
			if (left != null)
				left.postorder();
			if (right != null)
				right.postorder();
			System.out.println(val);
		}
	}
	private Node root;
	public BinaryTree() {
		root = null;
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
					return;
				}
				p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, null, null);
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
