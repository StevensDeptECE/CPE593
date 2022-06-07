
public class LinkedList2019F {
  private static class Node {
    int data;
    Node next;
  };
  private Node head;
  public LinkedList2019F() { head = null; }
  public void addEnd(int v) {  //O(n)
    if (head == null) { // O(1)
      head = new Node();
      head.data = v;
      head.next = null;
      return;
    }
    Node p;
    for (p = head; p.next != null; p = p.next) //O(n)
      ;
    // p = last element
    Node temp = new Node(); //O(1)
    temp.data = v;
    temp.next = null;
    p.next = temp;
  }
  public void addStart(int v) {  //O(1)
    Node temp = new Node();
    temp.data = v;
    temp.next = head;
    head = temp;
  }
  public void removeStart() {
    if (head == null)
      return;
    Node temp = head;
    head = head.next; // write pseudocode showing that you know that free(temp)
  }

  public void removeEnd() {
    if (head == null)
      return;
    
    Node p = head;
    if (p.next == null) {
      head = null;
      return;
    }
      
    Node q = p;
    p = p.next;
    for ( ; p.next != null; q = p, p = p.next) //O(n)
      ;
    // p points to last element
    // q points to the element just before
    q.next = null; // stop pointing to the last element that has been deleted
  }

  public int size()  { // O(n)
    int count = 0;
    for (Node p = head; p != null; p=p.next)
      count++;
    return count;
  }

  public int get(int i) { //O(n)
    for (Node p = head; p != null; i--, p = p.next)
      if (i == 0)
        return p.data;
    throw new RuntimeException("Out of bounds");
  }
  
  public static class Iterator {
  private  Node current;
    public Iterator(LinkedList2019F list) { current = list.head; }
    boolean hasNext() { return current != null; }
    void next() { current = current.next; }
    int getValue() {
      return current.data;
    }
  };

  public static void main(String[]args) {
    LinkedList2019F a = new LinkedList2019F();
    a.addEnd(4);
    a.addStart(3);
    final int n = 10;

    for (int i = n-1; i >= 0; i--)//O(n)
      a.addStart(i); 
    
    for (LinkedList2019F.Iterator i = new LinkedList2019F.Iterator(a); i.hasNext(); i.next() )
      System.out.print(i.getValue());

  }
};
