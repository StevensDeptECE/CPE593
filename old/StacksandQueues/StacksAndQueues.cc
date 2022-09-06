class Stack {
private:
	//	LinkedList impl;  // addFirst O(1), addLast O(n) removeFirst O(1) removeLast O(n)
	GrowArray impl; // addFirst O(n) addLast O(1) removeFirst O(n) removeLast O(1)
public:
	void push(int v) { impl.addFirst(v);   }
	int pop() { return impl.removeFirst() }
	bool isEmpty() const {return impl.isEmpty(); }
};

class Queue {
private:
	LinkedList2 impl; // has head and tail
public:
	void enqueue(int v) { impl.addLast(v); } //O(1)
	int dequeue() { impl.removeFirst(); } //O(1)
	bool isEmpty() const { return impl.isEmpty(); )

};
