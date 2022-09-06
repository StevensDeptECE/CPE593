class RBTree {
private:
  enum color {red, black};
  class Node {
    public:
      Node* parent;
      Node* left;
      Node* right;
      color c;
      int key;

      Node(int key, Node* p = nullptr) : parent(p), left(nullptr), right(nullptr), key(key), c(red) {} // root node starts out black
  };

  Node* root;
public:
  RBTree() : root(nullptr) {}
  void add(int v) {
    if (root == nullptr) {
      root = new Node(v);
      return;
    }
    Node* p = root;
    while (true) {
      if (v >= p->key) {
        if (p->right != nullptr) {
          p = p->right;
        } else {
          p->right = new Node(v, p);
          insert(p);
          return;
        }
      } else {
        if (p->left != nullptr) {
          p = p->left;
        } else {
          p->left = new Node(v, p);
          insert(p)
          return;
        }
      }
    }
  }
  void insert(Node* p) {
    if (p->c == black)
      return;

  }
};

int main() {
  RBTree tree;
  tree.add(3);

}