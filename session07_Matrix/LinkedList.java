public class LinkedList {
    private static class Node {
	int val;
	Node next;
	public Node(int v, Node n) { val = v; next = n; }
    }
    private Node head;
    private Node tail;
    public LinkedList() {
	head = tail = null;
    }
    /* only in C++, but for the test, you need to show pseudocode
    public void destructor() {
	for (Node p = head; p != null; p = p.next)
	    delete p;
    }
     */

    public void addStart(int v) {
	head = new Node(v, head);
	if (tail == null)
	    tail = head;
    }

    public void addEnd(int v) {
	if (tail == null) {
	    head = tail = new Node(v, null);
	    return;
	}
	tail.next = new Node(v, null);
    }

    public void insert(int pos, int val) {
	if (head == null) {
	    head = tail = new Node(val, null);
	    return;
	}
	Node p = head;
	for (; pos > 0; pos--)
	    p = p.next;
	p.next = new Node(val, p.next);
    }

    public boolean isEmpty() {
	return head == null;
    }
    
    public void removeStart() {
	if (head == tail) {
	    head = tail = null;
	    return;
	}
	head = head.next;
    }

    public void removeEnd() {
	// left as an exercise!!!
    }

    public static class Iterator { // LinkedList.Iterator
	private Node current;
	public Iterator(LinkedList list) {
	    current = list.head;
	}
	public boolean done() {
	    return current == null;
	}

	public void next() {
	    current = current.next;
	}
	public int getValue() {
	    return current.val;
	}
    }

    public Iterator  begin() {
	return new Iterator(this);
    }
    
    public static void main(String[] args) {
	LinkedList a = new LinkedList(); // O(1)
	// head = null, tail = null
	a.addStart(5); //O(1)
	a.addEnd(3);   //O(1)
	final int n = 10;
	for (int i = 0; i < n; i++)
	    a.insert(i, i); // O(n*n)

	for (int i = 0; i < n; i++) // O(n*n)
	    System.out.print(a.get(i) + " ");
	System.out.println();

	for (Node p = a.head; p != null; p = p.next) {
	    System.out.print(p.val + " ");
	}

	for (LinkedList.Iterator i = a.begin(); !i.done(); i.next())
	    System.out.println(i.getValue());
	



	
    }

}
