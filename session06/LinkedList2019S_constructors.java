
public class LinkedList2019S_constructors {
	private static class Node { // LinkedList2019S.Node
		public int val;
		public Node next;

		public Node(int v, Node n) {
			val = v; next = n;
		}
	}

	private Node head;
	public LinkedList2019S_constructors() {
		head = null; //O(1)
	}
	public void addStart(int v) { //O(1)
		head = new Node(v, head);
	}

	public void addEnd(int v) {
		Node temp = new Node(v, null);
		Node p;
		if (head == null) {
			head = temp;
			return;
		}
		// invariant: head is not null, list has at least 1 element
		for (p = head; p.next != null; p = p.next)
			;
		//  p is pointing to last element
		p.next = temp;
	}

	public void insert(int pos, int v) { //O(n)
		Node p = head;
		while (pos > 0) {
			p = p.next;
			pos--;
		}
		p.next = new Node(v, p.next);
	}

	public int removeStart() {
		Node temp = head;
		head = head.next;
		return temp.val;
	}

	public int removeEnd() {
		Node p = head;
		Node q = p.next;
		if (q == null) {
			int v = head.val;
			head = null;
			return v;
		}
		
		for (; q.next != null; p = q, q = q.next)
			;
		p.next = null;
		return q.val;
	}

	public String toString() {
		StringBuilder b = new StringBuilder();
		for (Node p = head; p != null; p = p.next)
			b.append(p.val).append(' ');
		return b.toString();
	}
	
	public static void main(String[] args) {
		LinkedList2019S_constructors a = new LinkedList2019S_constructors();
		for (int i = 0; i < 10; i++)
			a.addStart(i);
		for (int i = 0; i < 10; i++)
			a.addEnd(i);
		a.removeStart();
		a.removeEnd();
		System.out.println(a);
	}
		
}
