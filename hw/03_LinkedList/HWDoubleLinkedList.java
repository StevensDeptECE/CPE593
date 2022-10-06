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
			HWDoubleLinkedList a = new HWDoubleLinkedList(500); // empty list, with 500 elements
    		int n = Integer.parseInt(args[0]);
			for (int i = 0; i < 500; i++)
				a.addEnd(i); // really fast!
		
			for (int i = 0; i < n; i++)
				a.addEnd(i); // every time you need to grow, double
		
			a.addStart(5);
		
			for (int i = 0; i < n/2; i++)
				a.removeEnd();
		
			for (int i = 0; i < n/2; i++)
				a.removeStart();
		
		
			a.removeEvens();
			System.out.println(a);
		}
    		catch (NumberFormatException nfe) {
			System.out.println("Argument must be an integer value");
		}

	}
}
