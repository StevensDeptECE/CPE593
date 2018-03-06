#include <iostream>
using namespace std;

class LinkedList1 {
private:
  class Node {
  public:
    int data;
    Node* next;
    Node(int v, Node* next) : data(v), next(next) {}
  };
  Node* head;
  int size_;
public:
  LinkedList1() : head(nullptr), size_(0) {}
  ~LinkedList1() { // O(n)
    for (Node* p = head; p != nullptr; ) {
      Node* q = p;
      p = p->next;
      delete q;
    }
  }
  LinkedList1(const LinkedList1& orig) {
    if (orig.head == nullptr) { // zero elements
      head = nullptr;
      return;
    }
    head = new Node(orig.head->data, nullptr);
    if (orig.head->next == nullptr) { // 1 element
      return;
    }
    // guaranteed orig has at least 2 elements
    // head is a copy of the 1st element of orig
    Node* q = head;
    for (Node* p = head->next; p != nullptr; p = p->next) {
      Node* temp = new Node(p->data, nullptr);
      q->next = temp;
      q = temp;
    }    

  }
  LinkedList1& operator =(const LinkedList1& orig) = delete;

#if 0
  LinkedList1& operator =(const LinkedList1& orig) {
    LinkedList1 copy(orig);
    swap(head, copy.head);
    return copy;
  }
#endif

  void addFirst(int v) { //O(1)
    size_++;
    head = new Node(v, head);
  }
  void addEnd(int v) { //O(n)
    size_++;
    Node* p;
    if (head == nullptr) {
      head = new Node(v, nullptr);
      return;
    }
    
    for (p = head; p->next != nullptr; p = p->next) //O(n)
      ;
    p->next = new Node(v, nullptr);
    
  }
  void removeFirst() { // O(1)
    size_--;
    Node* p = head;
    head = head->next;
    delete p;
  }
  void removeEnd() {
    if (head == nullptr) {
      return;
    }
    size_--;
    Node* p = head;
    if (p->next == nullptr) {
      delete p;
      head = nullptr;
      return;
    }
    Node* q = p->next;
    for (p = head; q->next != nullptr; p = q, q = q->next) //O(n)
      ;
    // q points to the last element
    // p points to 2nd to last
    delete q;
    p->next = nullptr;
  }
  int size() const { //O(n)
    int count = 0;
    for (Node* p = head; p != nullptr; p = p->next)
      count++;
    return count;
  }

  int cachedSize() const { //O(1)  (but it took O(n) to build this)
    return size_;
  }
  friend ostream& operator <<(ostream& s, const LinkedList1& list){
    for (Node* p = list.head; p != nullptr; p = p->next)
      s << p->data << ' ';
    return s;
  }
  class Iterator {
  private:
    Node* current;
  public:
    Iterator(const LinkedList1& list) {
      current = list.head;
    }
    bool operator !() const {
      return current != nullptr;
    }

    Iterator& operator ++() {
      current = current -> next;
      return *this;
    }

    int operator *() const {
      return current->data;
    }

  };
};

void f(LinkedList x) {

}
int main() {
  LinkedList1 a;
  a.addFirst(3);
  a.addFirst(1);
  a.addEnd(4);
  a.removeEnd();
  a.removeFirst();
  for (int i = 0; i < 10; i++)
    a.addFirst(i);
  cout << a.size() << '\n';
  cout << a << '\n';
  // DIE!  LinkedList1 b = a;
  f(a);
  for (LinkedList1::Iterator i = a; !i; ++i) {
    cout << *i << ' ';

  
}
