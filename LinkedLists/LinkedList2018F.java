public class LinkedList2018F {
	private static class Node { // LinkedList.Node
		int v;
		Node next;
	}
	private Node head;
	public LinkedList2018F() {
		head = null;
	}

	public void addEnd(int v) {
		if (head == null) {
			addStart(v);
			return;
		}
		// invariant: head is not null, list has at least 1 element
		Node p;
		for (p = head; p.next != null; p= p.next)
			;
		Node temp = new Node();
	  temp.v = v;
		temp.next = null;
		p.next = temp;		
	}
	public void addStart(int v) {
    Node temp = new Node();
		temp.v = v;
		temp.next = head;
		head = temp;
	}
	public void removeEnd() {
		if (head == null)
			return;
		if (head.next == null) {
			head = null;
			return;
		}
		// invariant: there are at least 2 elements
		Node p, q;
		for (p = head, q = p.next; q.next != null; p = q, q = q.next)
			;
		p.next = null;
	}
	public void removeStart() {
		head = head.next;
	}
	public String toString() {
		StringBuilder b = new StringBuilder();
		for (Node p = head; p != null; p = p.next)
			b.append(p.v).append(' ');
		return b.toString();
	}
	public static void main(String[]args) {
		LinkedList2018F a = new LinkedList2018F();
		for (int i = 10; i > 0; i--)
			a.addStart(i);
		System.out.println(a);
	}
}

