public class LinkedList2023S {
  private static class Node { // LinkedList2023S.Node
    int val;
    Node next;
  }
  private Node head;
  
  public LinkedList2023S() {
    head = null;
  }
  public void addStart(int v){
    Node temp = new Node();
    temp.next = head;
    temp.val = v;
    head = temp;
  }
  public void addEnd(int v){ 
    Node p;
    for (p = head; p.next != null; p = p.next)
      ;
    Node temp = new Node();
    temp.next = null;
    temp.val = v;
    if (head == null) {
      head = temp;        
    } else
        p.next = temp;
  }
  public void insert(int i, int v){ }
  public bool isEmpty() { //O(1)
    return head == null;
  }

  public int getSize() { //O(n)
    int count = 0;
    for (Node p = head; p != null; p= p.next) 
       count++;
    return count;
  }
  public void removeStart() {
    head = head.next;
  }
  public void removeEnd() {
    Node p = head;
    if (head == null) {
        return;
    }
    Node q = p.next;
    if (q == null) {
        head = null;
        return;
    }
    // invariant: at least 2 nodes, p and q
    for (; q.next != null; p = q, q = q.next)
      ;
    p.next = null;
  } 
}