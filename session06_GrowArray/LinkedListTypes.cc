class LinkedList1 {
private:
  class Node { // LinkedList1::Node  LinkedList1.Node 
  public:
    int data;
    Node* next;
  };
  Node* head;  
};

class LinkedList2 {
private:
  class Node { // LinkedList1::Node  LinkedList1.Node 
  public:
    int data;
    Node* next;
  };
  Node* head;
  Node* tail;

};

class DoubleLinkedList1 {
private:
  class Node {
  public:
    int data;
    Node* next;
    Node* prev;
  };
  Node* head;


};

class DoubleLinkedList2 {
  class Node {
  public:
    int data;
    Node* next;
    Node* prev;
  };
  Node* head;
  Node* tail;

};


/**
   special case head->prev can be used for tail
 */
class DoubleLinkedList3 {
  class Node {
  public:
    int data;
    Node* next;
    Node* prev;
  };
  Node* head;

};

