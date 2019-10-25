public class LinkedList1<T> {
	private static class Node { // LinkedList1.Node
		T data;
		Node next;
	}
  private Node head;

	public LinkedList1() { head = null; }
	public void addStart(T v) { //O(1)
		Node temp = new Node();
		temp.data = v;
		temp.next = head; // point to the head of the old list
		head = temp; // you are now the front
	}

	public void addEnd(T v) {
		if (head == null) {
			head = new Node();
			head.data = v;
			head.next = null;
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next)
			;
		// p points to the last node
	}

	public T removeStart() { //O(1)
		if (head == null)
			return;
		T val = head.data;
		head = head.next;
		return val;
	}

	public void removeEnd() { // O(n)
		if (head == null)
			return;
		if (head.next == null) {
			head = null;
			return;
		}
		// guaranteed at least 2 elements
		Node p = head;
		for (Node q = p.next; q.next != null; ) { //O(n)
			p = q;
			q = q.next;
		}
		// p is pointing to 2nd to last element
		p.next = null;
	}
  public boolean isEmpty() {
		return head == null;
	}
	
	int size() { //O(n)
		int count = 0;
    for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}

	public static void main(String[]args) {
		LinkedList1 list = new LinkedList1();
		list.addEnd(3);
		list.addStart(1);
		for (int i = 0; i < 10; i++)
			list.addStart(i);
		list.removeEnd();
		list.removeStart();
		System.out.println(list);
		System.out.println(list.size());
	}
}




