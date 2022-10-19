public class HWDoubleLinkedList {
	private static class Node { // static class in Java does not have pointer to the container
		Node next;
		Node prev;
		int val;
	}

	private Node head;
	private Node tail;
	public HWDoubleLinkedList() {
		head.next= new Node();
	}

	public void addStart(int v) {

	}

	public void addEnd(int v) {

	}

	public void removeStart() {

	}

	public void removeEnd() {

	}

	// insert v before pos. insert(0,v) would insert at the front.
	public void insert(int pos, int v) {

	}
	// implement to print out the list
	public String toString() {
	    // Don't forget, use StringBuilder!!!
		return "Implement this!";
	}

	public static void main(String[] args) {
		try {
			HWDoubleLinkedList a = new HWDoubleLinkedList();
    			int n = Integer.parseInt(args[0]);
			for (int i = 0; i < n; i++)
				a.addStart(i);
        
			for (int i = 0; i < n; i++)
				a.addEnd(i);
        
			for (int i = 0; i < 3*n/2; i++)
				a.removeStart();
			for (int i = 0; i < n/2 - 5; i++)
				a.removeEnd();
			System.out.println(a);
			for (int i = 0; i < 10; i++)
				a.insert(1, i);
			System.out.println(a);
		}
    		catch (NumberFormatException nfe) {
			System.out.println("Argument must be an integer value");
		}

	}
}
