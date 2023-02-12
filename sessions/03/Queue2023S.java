public class Queue2023S {
    private LinkedList impl;

    public Queue() { //O(1)
         impl = new LinkedList(); }
    public void enqueue(int v) { //O(1)
        impl.addStart(v);
    }
    public int dequeue() { //O(n)
        return impl.removeEnd();
    }

    public bool isEmpty() {
        return impl.isEmpty();
    }
}


class Queue2 {
    private LinkedList2 impl;

    public Queue2() { //O(1)
         impl = new LinkedList2(); }
    public void enqueue(int v) { //O(1)
        impl.addEnd(v); 
    }
    public int dequeue() { //O(1)
        return impl.removeStart();
    }

    public bool isEmpty() {
        return impl.isEmpty();
    }
}


class Queue3 {
    private DynamicArray impl;

    public Queue3(int capacity) { //O(1)
         impl = new DynamicArray(capacity); }
    public void enqueue(int v) { //O(n)
        impl.addStart(v);
    }
    public int dequeue() { //O(1)
        return impl.removeEnd();
    }

    public bool isEmpty() {
        return impl.isEmpty();
    }
}