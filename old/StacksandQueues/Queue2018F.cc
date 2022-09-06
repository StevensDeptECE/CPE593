class Queue {
public:
	void enqueue(int v);
	int dequeue();
  bool isEmpty() const;
	int size() const;
	
};

class Stack {
public:
	void push(int v);
	int pop();
  bool isEmpty() const;
	int size() const;
};
