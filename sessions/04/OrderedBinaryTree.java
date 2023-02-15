/*
                   9
                /    \
               5      80
            /  \     /  \
           1    7   62   103
                          \
                          200
                            \
                            205


inorder: 1 5 7 9 ...
preorder: 9 5 1 7 80 62 103 200 205
postorder: 1 7 5 62 205 200 103 80 9

        3                       2            
       /                       / \
      2                       1   3
    /
   1




*/



public class OrderedBinaryTree {
    private static class Node { // OrderedBinaryTree.Node
        int val;
        Node left, right;
        public Node(int v) {
            val = v;
            left = right = null;
        }
        public void inorder() {
            if (left != null)
              left.inorder();
            System.out.print(val + " ");
            if (right != null)
              right.inorder();
        }

        public void preorder() {
            System.out.print(val + " ");
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
            System.out.print(val + " ");
        }
    }

    private Node root;

    public OrderedBinaryTree() {
        root = null;
    }
    public void add(int v) {
        if (root == null) {
            root = new Node(v);
            return;
        }
        Node p = root;
        while (true) {
            if (p.val < v) {
                if (p.right == null) {
                    p.right = new Node(v);
                    return;
                }
                p = p.right;
            } else {
                if (p.left == null) {
                  p.left = new Node(v);
                  return;
                }
                p = p.left;
            }
        }
    }
    public void inorder() {
        if (root != null)
          root.inorder();        
    }
}