class BinaryTree {
private:
  class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node(int v, Node* L, Node* r) : val(v), left(L), right(R) {}
    void inorder() {
      if (left != nullptr)
	left->inorder();
      cout << val;
      if (right != nullptr)
	right->inorder();
    }

    void preorder() {  
      cout << val;
      if (left != nullptr)
	left->preorder();
      if (right != nullptr)
	right->preorder();
    }
    void postorder() {
      if (left != nullptr)
	left->postorder();
      if (right != nullptr)
	right->postorder();
      cout << val;      
    }
  };
  Node * root;
public:
  void add(int v) {
    if (root == nullptr) {
      root = new Node(v, nullptr, nullptr);
      return;
    } 
  }
  void inorder() {
    if (root != nullptr)
      root->inorder();
  }
  void preorder() {}
  void postorder() {}
}
