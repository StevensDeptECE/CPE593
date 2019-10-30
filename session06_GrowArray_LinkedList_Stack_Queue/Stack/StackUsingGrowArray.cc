class Stack {
private:
	GrowArray a;
public:
	void push(int v) {
		a.addEnd(v);
	}
	int pop() {
		return a.removeEnd();
	}
	bool isEmpty() {
		return a.isEmpty(); //    in GrowArray  bool isEmpty() { return used == 0; }
	}
	
}
