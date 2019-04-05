#include <iostream>
using namespace std;

class LinkedList1 {
private:
  class Node {
  public:
    int data;
    Node* next;
  };
  Node* head;
  int size_;
public:
  LinkedList1() : head(nullptr), size_(0) {}
  ~LinkedList1() { // O(n)
    for (Node* p = head; p != nullptr; p = p->next) {
      Node* q = p;
      p = p->next;
      delete q;
    }
  }
  void addFirst(int v) { //O(1)
    size_++;
    Node* temp = new Node();
    temp->data = v;
    temp->next = head;
    head = temp;
  }
  void addEnd(int v) { //O(n)
    size_++;
    Node* p;
    if (head == nullptr) {
      head = new Node();
      head->data = v;
      head->next = nullptr;
      return;
    }
    
    for (p = head; p->next != nullptr; p = p->next) //O(n)
      ;
    Node* temp = new Node();
    temp->data = v;
    temp->next = nullptr;
    p->next = temp;
  }
  int removeFirst() { // O(1)
    size_--;
    Node* p = head;
		int v = p->val;
    head = head->next;
    delete p;
		return v;
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
	int start() {
		return head->data;
	}

	bool isEmpty() const {
		return head == nullptr;
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

};

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
}



  
