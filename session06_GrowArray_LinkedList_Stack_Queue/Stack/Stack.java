public class Stack<T> {
	private LinkedList1<T> impl;

	public Stack() { impl = new LinkedList1<>(); }
	public void push(T val) { //O(1)
    impl.addStart(val); //O(1)
	}
	
	public T pop() {
		return impl.removeStart(); //O(1)
	}
	
	public boolean isEmpty() {
		return impl.isEmpty();
	}
}
