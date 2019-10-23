class LinkedList1 {
private:
	class Node {
	public:
		int val;
		Node* next;
	};
	Node* head;
public:
	void addFirst(int v); //O(1)
	void addLast(int v); //O(n)
	int removeFirst(); // O(1)
	int removeLast(); //O(n)
	int size() const;  // O(n)
	bool isEmpty(); // O(1)
};

class LinkedList2 {
private:
	class Node {
	public:
		int val;
		Node* next;
	};
	Node* head;
	Node* tail;
public:
	void addFirst(int v); //O(1)
	void addLast(int v); //O(1)
	int removeFirst(); // O(1)
	int removeLast();//O(n)
	int size() const;  // O(n)
	bool isEmpty(); // O(1)
};

class LinkedList3 {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node* prev;
	};
	Node* head;
public:
	void addFirst(int v); //O(1)
	void addLast(int v); //O(n)
	int removeFirst(); // O(1)
	int removeLast();//O(n)
	int size() const;  // O(n)
	bool isEmpty(); // O(1)
};

class LinkedList4 {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	void addFirst(int v); //O(1)
	void addLast(int v); //O(1)
	int removeFirst(); // O(1)
	int removeLast();//O(1)
	int size() const;  // O(n)
	bool isEmpty(); // O(1)
};


class Stack {
private:
  LinkedList1 impl;
public:
	void push(int v) { impl.addFirst(v);}
	int pop() { return impl.removeFirst(); }
  bool isEmpty() { return impl.isEmpty(); }
};

class Queue {
private:
  LinkedList2 impl;
public:
	void enqueue(int v) { impl.addLast(v);  }
	int dequeue() { return impl.removeFirst(); }
	bool isEmpty() { return impl.isEmpty(); }
};

		
