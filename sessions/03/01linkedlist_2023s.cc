

class LinkedList {
private:
   class Node { // LinkedList::Node
     int val;
     Node* next;
     Node(int v, Node* n) : val(v), next(n) {}
   };
   Node* head;
public:
  LinkedList() : head(nullptr) {}
  ~LinkedList() {
    Node* temp; 
     for (Node* p = head; p != nullptr; p = temp) {
        temp = p->next;
       delete p;
     }
  }
  LinkedList(const LinkedList& orig) = delete;
  LinkedList& operator =(const LinkedList& orig) = delete;
  void addStart(int v) {
    head = new Node(v, head);
    //Node* temp = new Node;
    //temp->val = v;
    //temp->next = head;
    //head = temp;
  }
  void addEnd(int v) {
     if (head == nullptr) {
        head = new Node(v, nullptr);
        return;
     }
     Node* p;
     for (p = head; p->next != nullptr; p = p->next) {
     }
     //   p = pointing to last element
     p->next = new Node(v, nullptr);
  }

// insert after the indexth element
  void insert(int index, int val) {
    Node* p = head;
    for (int i = 0; i < index; i++)
      p = p->next;
    // p is pointing to ith node
    //p->next = new Node(val, p->next);  
    Node* temp = new Node();
    temp->val = val;
    temp->next = p->next;
    p->next = temp;
  }
  void removeStart() { //O(1)
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void removeEnd() { //O(n)
    
    if (head == nullptr) {
        return;
    }
    Node*p = head;
    Node* q = p->next;
    if (q == nullptr) {

        delete head;
        head = nullptr;
        return;
    }
    // guaranteed: 2 elements
    for (; q->next != nullptr; p = q, q = q->next)
      ;
    delete q;
    p->next = nullptr;
    // p = the last element
  }
  // see 


  void insert(Iterator& i, int val) {}

  class Iterator {
    private:
      Node* current;
    public:
     Iterator(LinkedList& list){ current = list.head; }
     void operator ++() { current = current ->next; }
     bool operator !() const { return current != nullptr; }
     int operator *() const { return current->val; } 
  };

};