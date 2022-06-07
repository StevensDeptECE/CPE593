#include <iostream>
using namespace std;

class LinkedList {
private:
  class Node {
  public:
    int data;
    Node* next;
    Node(int v, Node* next) : data(v), next(next) {}
  };
  Node* head;
public:
  LinkedList() : head(nullptr) {}
  ~LinkedList() {
    Node* q;
    for (Node* p = head; p != nullptr; ) {
      q = p;
      p = p->next;
      delete q;
    }

  }
#if 0
  // this is a copy constructor
  LinkedList(const LinkedList& orig) {
    if (orig.head == nullptr) {
      head = nullptr;
      return;
    }
    head = new Node(orig.head->data, nullptr);
    Node* q = head;
    for (Node* p = orig.head->next; p != nullptr; p=p->next, q = q->next)
      q->next = new Node(p->data, nullptr);
  }
#endif

  LinkedList(const LinkedList& orig)  = delete;
  void operator =(const ListList& orig) = delete;
  
  void addEnd(int v) {  //O(n)
    if (head == nullptr) { // O(1)
      head = new Node(v, nullptr);
      return;
    }
    Node* p;
    for (p = head; p->next != nullptr; p = p->next) //O(n)
      ;
    // p = last element
    p->next = new Node(v, nullptr);
  }
  void addStart(int v) {  //O(1)
    head = new Node(v, head);
  }
  void removeStart() {
    if (head == nullptr)
      return;
    Node* temp = head;
    head = head->next;
    delete temp; // free the memory
  }

  void removeEnd() {
    if (head == nullptr)
      return;
    
    Node* p = head;
    if (p->next == nullptr) {
      delete p;
      head = nullptr;
      return;
    }
      
    Node* q = p;
    p = p->next;
    for ( ; p->next != nullptr; q = p, p = p->next) //O(n)
      ;
    // p points to last element
    // q points to the element just before
    delete p;
    q->next = nullptr; // stop pointing to the last element that has been deleted
  }

  int size() const { // O(n)
    int count = 0;
    for (Node* p = head; p != nullptr; p=p->next)
      count++;
    return count;
  }

  int get(int i) const { //O(n)
    for (Node* p = head; p != nullptr; i--, p = p->next)
      if (i == 0)
        return p->data;
    throw "Out of bounds";
  }
  class Iterator {
  private:
    Node* current;
  public:
    Iterator(LinkedList& list) : current(list.head) {}
    bool operator !() const { return current != nullptr; }
    void operator ++() { current = current->next; }
    int& operator *() const {
      return current->data;
    }
  };
};

void f(LinkedList x) {

}

int main() {
  LinkedList a; // create an empty list O(1)
  a.addEnd(4);
  a.addStart(3);
  const int n = 10;
  //  for (int i = 0; i < n; i++) //O(n^2)
  //    a.addEnd(i); 

  for (int i = n-1; i >= 0; i--)//O(n)
    a.addStart(i); 

  //  for (int i = 0; i < a.size(); i++) //O(n^2)
  //    cout << a.get(i);

  for (LinkedList::Iterator i = a; !i; ++i)
    *i *= 3;

  // O(n)  
  for (LinkedList::Iterator i = a; !i; ++i)
    cout << *i << ' ';
  cout << '\n';

  LinkedList b = a;
  LinkedList c(a);
  f(a);

  c = b;



  
  
}
