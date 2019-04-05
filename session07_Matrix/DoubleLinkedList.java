public class DoubleLinkedList {
    private static class Node {
	private int val;
	private Node next;
	private Node prev;
    }
    private Node head, tail;


    public static void main() {
	DoubleLinkedList a = new DoubleLinkedList();
	a.addFirst(5);
	a.addLast(3); // 5 3
	a.removeLast(); // 5
	a.removeFirst(); // empty
	for (int i = 0; i < 10; i++)
	    a.addLast(i); // 0 1 2 3 4 5 6 7 8 9
	System.out.println(a);
    }
}
