import java.awt.*;
import java.util.*;

public class RBTree {
	private static enum Color { RED, BLACK};
	static class Node {
		int data;
		Node left, right, parent;
		Color c;
		public Node(int v, Node L, Node R, Node P) {
			data = v; left = L; right = R; parent = P;
			c = Color.RED;
		}

		public Node(int v, Node P) {
			data = v; left = right = null; parent = P;
			c = Color.RED;
		}
		
		public void print() {
			if (left != null) {
				left.print();
				System.out.println(' ');
			}
			System.out.print(data);
			if (right != null) {
				right.print();
				System.out.println(' ');
			}
		}
		public void draw(Graphics g, int x, int y,
										 int d,
										 int dx, int dy) {
      g.setColor(c == Color.RED ? java.awt.Color.RED : java.awt.Color.BLACK);
			g.fillOval(x,y,d,d);
      g.setColor(java.awt.Color.WHITE);
			g.drawString(data + "", x+d/3,y+d*2/3);
      g.setColor(java.awt.Color.BLACK);
			if (left != null) {
        g.drawLine(x,y+d, x-dx, y+dy);
				left.draw(g, x-dx, y+dy, d, dx, dy);
			}
			if (right != null) {
				g.drawLine(x+d,y+d, x+d+dx, y+dy);
				right.draw(g, x+d+dx, y+dy, d, dx, dy);
			}
		}
		
		public void inorder() {
			if (left != null)
				left.inorder();
			System.out.print(data);
			if (right != null)
				right.inorder();
		}
		
		public void preorder() {
			System.out.print(data);
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
			System.out.print(data);
		}

		public Node uncle() {
			if (parent == null || parent.parent == null)
				return null;

			if (parent.parent.left == parent) // if grandparent's left child
				return parent.parent.right;
			else
				return parent.parent.left;
		}
		
		public void rotateLeft() {
      Node p = parent;
      Node g = p.parent;
      g.left = this;
      this.left = p;
      p.right = null;
    }
		public void rotateRight() {
      Node p = parent;
      Node g = p.parent;
      g.right = this;
      this.right = p;
      p.left = null;
    }
		public void repair() {
			if (parent == null) // case 1: you are now root
				c = Color.BLACK;
			else if (this.parent.c == Color.BLACK)
				return;
			else {
				Node g = parent.parent; // grandparent
        if (g == null)
          return;
				Node u = uncle();
				if (u != null) {
					if (u.c == Color.RED) {
						parent.c = Color.BLACK;
						u.c = Color.BLACK;
						g.c = Color.RED;
						g.repair();
					} else {  // case 4: uncle's color is BLACK
						if (this == parent.parent.left.right) {
							parent.rotateLeft();
							//TODO: needed?							this = this.left;
						} else if (this == parent.parent.right.left) {
							parent.rotateRight();
							//TODO: needed?							this = this.right; 
						}						
					}
				}
			}
		}

	}
	private Node root;

	public RBTree() {
		root = null;
	}
	
  public Node getRoot() { return root; }
	public void add(int v) {
		if (root == null) {
			root = new Node(v, null);
			return;
		}
		Node p = root;
		while (true)
			if (v < p.data) {
				if (p.left == null) {
					p.left = new Node(v, p);
					p.repair();
					return;
				} else
					p = p.left;
			} else {
				if (p.right == null) {
					p.right = new Node(v, p);
					p.repair();
					return;
				} else
					p = p.right;
			}
	}
		
  public void println() {
		root.print();
		System.out.println();
	}

  public static void main(String[] args) {
		RBTree t = new RBTree();
		int[] values = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
		for (int v : values) {
			t.add(v);
			t.println();
		}
	}
}
