public class LinkedList2021b {
	private static class Node {
		private int value;
		private Node next;
		public Node(int v, Node n) {
			value = v;
			next = n;
		}
	}

	private Node head;
	public LinkedList2021b() {
		head = null;
	}
	public void addEnd(int v) { //O(n)
		if (head == null) {
			head = new Node(v, null);
			return;
		}
		Node p = head;
    while (p.next != null ) {
			p = p.next;
		}
		p.next = new Node(v, null);
	}

	public void addStart(int v) { //O(1)
		head = new Node(v, head);
	}

  public void removeEnd() { //O(n)
		Node p = head;
		//Check for error condition:		if (p == null)
		Node q = p.next;
		if (q == null) {
			p.next = null;
			return;
		}
		while (q.next != null) {
			p = q;
			q = q.next;
		}
		// q points to last node p points to the 2nd last Node
		p.next = null;
	}

  public void removeStart() { //O(1)
			head = head.next;
	}

	public int getSize() { //O(n)
		int count = 0;
		for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}
	public boolean isEmpty() { //O(1)
		return head == null;
	}

	public int get(int n) { //O(n)     1         n/2        n
		Node p = head;
		for (int i = 0; i < n; i++)
			p = p.next;
		return p.value;
	}

	public static class Iterator {
		private Node current;
		public Iterator(Node n) {
			current = n;
		}
		public boolean hasNext() {
			return current != null;
		}

		public void next() {
			current = current.next;
		}

		public int get() {
			return current.value;
		}
	}

	public Node start() {
		return head;
	}
	
	public static void main(String[] args) {
		LinkedList2021b list = new LinkedList2021b();
		final int n = 10000;
		/* don't do this!
		for (int i = 0; i  < n; i++)
			list.addEnd(i); // 1 + 2 + 3 + ... N = O(n^2)
		// 0 1 2 3 4 5 ... 999999
		*/
		
		for (int i = n-1; i >= 0; i--) //O(n)
			list.addStart(i);

		/*
don't do this!
		long sum = 0;
		for (int i = 0; i < n; i++) //O(n^2)
			sum += list.get(i);
		*/

		long sum = 0;
		for (LinkedList2021b.Iterator i = new Iterator(list.start()); i.hasNext(); i.next())
			sum += i.get();
		System.out.println(sum);
	}
}
