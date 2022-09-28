#include <iostream>
using namespace std;

class LinkedList {
private:
  struct Node { // name is LinkedList::Node
    int val;
    Node* next;
    Node(int v, Node* n) : val(v), next(n) {}
  };

  Node* head;
public:
  LinkedList() : head(nullptr) {
  }
  ~LinkedList() {
    // delete EVERY NODE
    // lucky java programmers do not have to write this one
  }
  void addFirst(int val) {
    head = new Node(val, head);
  }

  void addLast(int val) {
    
  }
};

int main() {
  LinkedList a; // make me an empty LinkedList
  // We can't preallocate. What does that even mean???  LinkedList b(100);

  a.addFirst(3);
  a.addLast(1);
  a.addLast(4);
  a.addLast(1);
  a.addLast(5);
  a.addLast(2);
  a.removeLast();
  a.addLast(9);
  
}
