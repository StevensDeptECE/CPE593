class LinkedList1 {
 private static class Node { //  LinkedList1.Node 
     private int data;
     private Node next;
 }
 private Node head;  

};

class LinkedList2 {
    private static class Node { //  LinkedList2.Node 
	private int data;
	private Node next;
    }
    Node head, tail;

};

class DoubleLinkedList1 {
    private static class Node {
	int data;
	Node next, prev;
    }
    Node head;

};

class DoubleLinkedList2 {
    private static class Node {
	int data;
	Node next, prev;
    }
    Node head, tail;

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

