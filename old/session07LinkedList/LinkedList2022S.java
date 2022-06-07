public class LinkedList2022S {
	private class Node { // LinkedList2022S.Node
		int val;
		Node next;// 32bits * 8 = 4* 10^9 * 8 = 32Gb
	}

	private Node head;
	private Node tail;
	public LinkedList2022S() {
		head = null;
	}

	public void addStart(int v) {
		Node temp = new Node();
		temp.val = v;
		temp.next = head; // put yourself in front of the first element
		head = temp;
	}

	public void addEnd(int v) {
		if (head == null) {
			head = new Node();
			head.val = v;
			head.next  = null;
			return;
		}
		Node p;
    for (p = head; p.next != null; p = p.next)
			;
		//p = pointing to last element
		Node temp = new Node();
		temp.val = v;
		temp.next = null;
		p.next = temp;
	}

	public void removeStart() {
    head = head.next;
	}

	public void removeEnd() {
    Node p, q;

		if (head == null) {
			return; // What?
		}
	 
		p = head;
		if (p.next == null) {
      head = null;
			return;
		}
		// invariant: at least 2 elements
		for (q = p.next; q.next != null; p = q, q = q.next)
			;
		p.next = null;
	}
	
	public String toString() {
		//NOTE: This is the bad way! Use StringBuilder
		String s = "";
		for (Node p = head; p != null; p = p.next)
			s = s + p.val + ",";
		return s;
	}

	public static void main(String[] args) {
		LinkedList2022S list = new LinkedList2022S();
		for (int i = 0; i < 10; i++)
			list.addStart(i);
		for (int i = 0; i < 10; i++)
			list.addEnd(i);
		list.removeStart();
		list.removeEnd();
		System.out.println(list);
	}
}
