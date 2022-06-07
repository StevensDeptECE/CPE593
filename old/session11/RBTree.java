public class RBTree {
    private static class Node {
	int val;
	Node left, right, parent;
	enum Color { RED, BLACK};
	Color color;
	public Node(Node left, Node right, Node parent, int val) {
	    this.left = left; this.right = right; this.parent = parent; this.val = val;
	    color = Color.RED;
	}
	private Node grandparent() {
	    if (parent == null)
		return null;
	    return parent.parent;
	}
	
	private Node sibling() {
	    if (parent == null)
		return null;
	    return parent.left == this ? parent.right : parent.left;
	}
	private Node uncle() {
	    if (parent == null)
		return null;
	    return parent.sibling()
	}
	private void repairTree() {
	    if (this.parent == null) {
		insert_case1(); // root
	    } else if (this.parent.color == Color.BLACK) {
		return;
	    } else if (uncle().color == Color.RED) {
		insert_case3();
	    } else {
		insert_case4();
	    }
	}
	private void insert_case1() {
	    if (parent == null)
		color = Color.BLACK;
	}
	private void insert_case3() {
	    parent.color = Color.BLACK;
	    uncle().color = Color.BLACK;
	    grandparent().color = Color.RED;
	}

	private void insert_case4() {
	    Node p = parent;
	    Node g = grandparent();
	    if (this == g.left.right) {
		p.rotate_left();
		//NOT LEGAL Java???	this = this.left;
            } else if (this == g.right.left) {
		p.rotate_right();
		// NOT LEGAL in Java: this = this.right; 
	    }
	    insert_case4step2(n);
	}

	private void rotate_left() {
	    Node nnew = right;
	    assert(nnew != null); // since the leaves of a red-black tree are empty, they cannot become internal nodes
            this.right = nnew.left;
	    nnew.left = this;
	    nnew.parent = parent;
	    parent = nnew;
            // (the other related parent and child links would also have to be updated)
	}

	private void rotate_right() {
	    struct node *nnew = left;
	    assert(nnew != null); // since the leaves of a red-black tree are empty, they cannot become internal nodes
	    left = nnew.right;
	    nnew.right = this;
	    nnew.parent = n.parent;
	    n.parent = nnew;
	    // (the other related parent and child links would also have to be updated)
	}
	    
	public void insert(int v) {
	    if (v > val) {
		if (right != null)
		    right.insert(v);
		else {
		    right = new Node(null, null, this, v);
		    right.repairTree();
		}
	    } else {
		if (left != null)
		    left.insert(v);
		else {
		    left = new Node(null, null, this, v);
		    left.repairTree();
		}
	    }
		
	}
    }
    Node root; // a binary tree is a pointer to root
    public RBTree() {
	root = null;
    }

    public void add(int v) {
	if (root == null) {
	    root = new Node(null, null, null, v);
	    return;
	}
	root.insert(v);
        // repair the tree in case any of the red-black properties have been violated
        insert_repair_tree(n);

 // find the new root to return
 root = n;
 while (parent(root) != NULL)
  root = parent(root);
 return n;
}

		    
}
