public class LinkedList {
	private static class Node { // LinkedList.Node
    // inner class automatically has a pointer o the outer class
		int val;
		Node next;
		Node(int v, Node next) { val = v; this.next = next; }
	}

	private	Node head;

	private Node tail() { //O(n)
		Node p = head;
		if (p == null)
			return null;
		for ( p = head; p.next != null; p = p.next)
			;
		return p;
	}

	public LinkedList() {
		//		head = null;
	}
	public void addStart(int v) { //O(1)
		head =  new Node(v, head);
	}

	public void addEnd(int  v) {
		if (head == null) {
			head = new Node(v, null);
			return;
		}
		tail().next = new Node(v, null);
	}
	

	public static void main(String[] args) {
		LinkedList list1 = new LinkedList();
		list1.addStart(5);
		
	

}
