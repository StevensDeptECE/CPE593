public class LinkedList2021 {
	//	private class Node { // this class has a pointer to the outer class
	private static class Node { // this is more efficient in Java
		private int value;
		private Node next;
		public Node(int v, Node n) {
			value = v;
			next = n;
		}
	}

	private Node head;
	private int size;
	public LinkedList2021() {
		head = null;
	}
	public void addEnd(int v) { //O(n)
		if (head == null) {
			head = new Node();
			temp.value = v;
			temp.next = null;
			return;
		}
		Node p = head;
    while (p.next != null ) {
			p = p.next;
		}
		// p is pointing to last element
		Node temp = new Node(); //O(1)
		temp.value = v;         //O(1)
		temp.next = null;       //O(1)
		p.next = temp;
		size++;
	}

	public void addStart(int v) { //O(1)
		Node temp = new Node(); //O(1)
		temp.value = v;         //O(1)
		temp.next = head;       //O(1)
		head = temp;
		//this is same:		head = new Node(v, head);
		size++;
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
		size--;
		
	}

  public void removeStart() { //O(1)
		//Not necessary: this is checking for wrong semantics
		//if (head != null)
			head = head.next;
			size--; 
	}

	public int getSize() { //O(n)
		//		return size; having a size variable makes this O(1)
		// but maintaining size as list grows and shrinks is
		//O(n)

		int count = 0;
		for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}
	public boolean isEmpty() { //O(1)
		return head == null;
	}
}


/*
LinkedList a = new LinkedList();
while (!a.isEmpty()) {
	a.removeStart();
}


while (a.size() == 0) {
	a.removeStart();
}

*/

for (int i = 0; i < n; i++)
	a.addStart(i);

System.out.println(a.getSize()); 
