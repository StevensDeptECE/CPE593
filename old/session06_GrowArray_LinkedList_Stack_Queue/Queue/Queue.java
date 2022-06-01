public class Queue<T> {
	private LinkedList2<T> impl;

	public Queue() { impl = new LinkedList1<>(); }
	public void enqueue(T val) { //O(1)
		impl.addEnd(val); //O(1)
	}
	
	public T dequeue() {
		return impl.removeStart();
	}
	
	public boolean isEmpty() {
		return impl.isEmpty();
	}
}
