class DoubleLinkedList {
private:
	class Node {
	public:
		Node* next;
		Node* prev;
		int val;
	};

	Node* head;
	Node* tail;
public:
	DoubleLinkedList() {
	}

	void addStart(int v) {

	}

	void addEnd(int v) {

	}

	void removeStart() {

	}

	void removeEnd() {

	}

	// insert v before pos. insert(0,v) would insert at the front.
	void insert(int pos, int v) {

	}
	// implement to print out the list
	friend ostream& operator <<(ostream& s, const DoubleLinkedList& list) {

	}
};

int main() {
	DoubleLinkedList a;
	const uint32_t n = 1000000;
	for (int i = 0; i < n; i++)
		a.addStart(i);
	for (int i = 0; i < n; i++)
		a.addEnd(i);
	for (int i = 0; i < 3*n/2; i++)
		a.removeStart();
	
	for (int i = 0; i < n/2 - 5; i++)
		a.removeEnd();

	cout << a << '\n';
	for (int i = 0; i < 10; i++)
		a.insert(1, i);
	cout << a << '\n';
}
