#include <iostream>
using namespace std;

class LinkedList {
private:
  struct Node { // name is LinkedList::Node
    int val;
    Node* next;
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
    Node* temp = new Node();
    temp->val = val;
    temp->next = head;
    head = temp;
  }

  void addLast(int val) {
    Node* p;
    for (p = head; p->next != nullptr; p = p->next)
      ;
    //p=pointing to last element
    Node* temp = new Node();
    temp->val = val;
    temp->next = nullptr;
    p->next = temp;
  }
  void removeLast() { //O(n)
    // how to remove last element
#if 0
    // it's ok not to have this if your policy is ALWAYS CHECK BEFORE YOU remove
    if (head == nullptr) {
      return;
    }
#endif
    Node* p = head;
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
    }
    // at this point... guaranteed there are at least 2 nodes
    Node* q = p->next;
    for ( ; q->next != nullptr; p = q, q = q->next)
      ;
    // q is pointing to last element
    // p is pointing to the 2nd to last
    delete q;
    p->next = nullptr;
  }

  void removeFirst() { // O(1)
    Node* temp = head;
    head = head ->next;
    delete temp;
  }

  friend ostream& operator <<(ostream& s, const LinkedList& list) {
    for (Node* p = list.head; p != nullptr; p=p->next)
      s << p->val << ' ';
    return s;
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
  cout << a;
}
