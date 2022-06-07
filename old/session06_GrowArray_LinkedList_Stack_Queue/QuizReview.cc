class LinkedList {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node* prev;
		Node(int v, Node* n, Node* p) : val(v), next(n), prev(p) {}
	};
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {} //O(1)
	~LinkedList() { //O(n)
	  while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void addFirst(int v) { //O(1)
		head = new Node(v, head, nullptr);
		if (tail == nullptr)
			tail = head;
		else
			head->next->prev = head
	}

	void addLast(int v) {
		tail = new Node(v, nullptr, tail);
		if (head == nullptr)
			head = tail;
		else
			tail->prev->next = tail;
	}

	void removeFirst() {
		if (head == null)
			return;
		Node* temp = head;
		head = head->next;
		delete temp;
	}
};


class GrowArray {
private:
	int* data;
	int len;
	int capacity;
	void grow() {
		int* old = data;
		data = new int[2*capacity+1];
		for (int i = 0; i < len; i++) // memcpy(data, old, len* sizeof(int))
			data[i] = old[i];
		delete old;
		capacity= 2*capacity+1;
	}
public:
	GrowArray() { data = nullptr; len = 0; capacity = 0; }
	void addEnd(int v) { //O(1)
		if (len >= capacity)
			grow();
		data[len++] = v;
	}

};

int main() {
	const int n = 10000000;
	GrowArray a;
	for (int i = 0; i < n; i++)
		a.addEnd(i);
