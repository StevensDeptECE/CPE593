public class DoubleLinkedList2 implements Cloneable {
	private static class Node {
		int data;
		Node next, prev;
		Node(int v, Node n, Node p) {
			data = v; next = n; prev = p;
		}
	}
	private Node head, tail;

	public DoubleLinkedList2() {
		head = null;  tail = null;
	}
	public DoubleLinkedList2 clone() {
		DoubleLinkedList2 copy = new DoubleLinkedList2();
		if (this.head == null) { // this list is empty
			copy.head = null;
			copy.tail = null;
			return copy;
		}
		copy.head = new Node(this.head.data, null, null);
		if (head.next == null) {
			return;
		}
		// guaranteed: at least 2 elements in this
		Node q = copy.head; // q points to the new ones
		// p points to 2nd element of the original list (this)
		for (Node p = head.next; p != null; p = p.next) {
			Node temp = new Node(p.data, null, q);
			q.next = temp;
			q = q.next;
		}
	}
	public void addFirst(int v) {
    Node temp = new Node(v, head, null);
		if (head == null) {
			tail = temp;
		} else {
      head.prev = temp;
		}
		head = temp;
	}

	public void addEnd(int v) {
    Node temp = new Node(v, null, tail);
		if (tail == null)
			head = temp;
		else
			tail.next = temp;
		tail = temp;
	}
	public void removeFirst() {
		if (head == null)
			return;
		if (head.next == null) {
			head = tail = null;
			return;
		}
		head = head.next;
		head.prev = null;
	}
	public void removeEnd() {
		if (tail == null)
			return;
		if (tail.prev == null) {
			head = tail = null;
			return;
		}
		tail = tail.prev;
		tail.next = null;
	}
	public int size() {
		int count = 0;
		for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}

	public static class Iterator {
		private Node current;
		public Iterator(DoubleLinkedList2 list) {
			current = list.head;
		}
    public boolean hasNext() {
			return current != null;
		}

		public void next() {
			current = current.next;
		}

		public int getValue() {
			return current.data;
		}

	}
	
	public static void main(String[] args) {
		DoubleLinkedList2 list = new DoubleLinkedList2();
		for (int i = 0; i < 10; i++) {
			list.addEnd(i);
			list.addFirst(i);
		}
		for (Node p = list.head; p != null; p = p.next)
			System.out.print(p.data + " ");
		System.out.println();
		for (int i = 0; i < 10; i++) {
			list.removeEnd();
			list.removeFirst();
		}
		for (Node p = list.head; p != null; p = p.next)
			System.out.print(p.data + " ");
		System.out.println();
		for (DoubleLinkedList2v2.Iterator i = new DoubleLinkedList2v2.Iterator(list);
				 i.hasNext(); i.next()) {
      System.out.print(i.getValue());

		}
	}
}
