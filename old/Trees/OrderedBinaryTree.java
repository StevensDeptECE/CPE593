public class OrderedBinaryTree {
	private static class Node {
		int data;
		Node left, right;
		public Node(int v, Node L, Node R) {
			data = v; left = L; right = R;
		}
		public void print() {
			if (left != null)
				left.print();
			System.out.print(data);
			if (right != null)
				right.print();
		}
	}
	private Node root;
	public OrderedBinaryTree() { root = null; }
	public void add(int v) {
		if (root == null) {
			root = new Node(v, null, null);
			return;
		}
		Node p = root;
		while (true)
			if (v < p.data) {
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
