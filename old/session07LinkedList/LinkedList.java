public class LinkedList {
    private static class Node { // LinkedList.Node
        int data;
        Node next;
        public Node(int v, Node n) {
            data = v;
            next = n;
        }
    };

    private Node head;

    public LinkedList() { head = null; }
    public LinkedList(int v) { 
        head = new Node(v, null); 
    }

    public void addEnd(int v) {}
    public void addStart(int v) {}
    public void removeStart() {
        head = head.next;
    }
    public int getLength() {
        
    }

 }
 void insert(int i, int v) {
      
 }
};