class LinkedList {
private:
  class Node {
  public:
    int val;
    Node* next;
    Node(int v, Node* n) : val(v), next(n) {}
  };
  Node* head;
  Node* tail;
public:
  LinkedList(): head(nullptr), tail(nullptr) {}
  ~LinkedList() {
    for (Node* p = head; p != nullptr; ) {
      Node* temp = p;
      p = p->next;
      delete temp;
    }
  }
  LinkedList(const LinkedList& orig) {
    

  }
  LinkedList& operator =(constLinkedList& orig) {}
  void addFirst(int v) {
    Node* temp = new Node();
    temp->val = v;
    temp->next = head;
    head = temp;
    //    head = new Node(v, head);
    if (tail == nullptr)
      tail = head;
  }
  void addLast(int v) {
#if 0
    Node* temp = new Node();
    temp->val = v;
    temp->next = nullptr;
    tail->next = temp;
#endif
    if (tail == nullptr) {
      head = tail = new Node(v, nullptr);
      return;
    }
    tail->next = new Node(v, nullptr);
    

  }
  bool isEmpty() const {
    return head == nullptr;
  }
  
  void removeFirst() {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  
  void removeLast() {
    if (head == tail) {
      delete head;
      head = tail = nullptr;
      return;
    }
    Node* p;
    for (p = head; p->next != tail; p = p->next)
      ;
    p->next = nullptr;
    delete tail;
    tail = p;
  }
  void insert(int pos, int val) {
    Node* p = head;
    for (int i = 0; i < pos; i++)
      p = p->next;
    Node* temp = new Node(val, p->next);
    p->next = temp;
  }

  
  class Iterator {
  private:
    Node* current;
  public:
    Iterator(const LinkedList& list) {
      current = list.head;
    }
    bool operator !() const {
      return current != nullptr;
    }
    // this is ++i
    void operator ++() {
      current = current->next;
    }
    
    // thisoperator is i++
    void operator ++(char*) {
      current = current->next;
    }
    int operator *() const {
      return current->val;
    }
  };
};

int main() {
  LinkedList a;
  a.addFirst(3);
  a.addLast(4);
  a.insert(0, 1); // 3 1 4


  for (Node* p = a.head; p != nullptr; p = p->next) {
    cout << p->val;
  }

  for (LinkedList::Iterator i = a; !i ; ++i)
    cout << *i << " ";
  cout << '\n';

  
  
}
