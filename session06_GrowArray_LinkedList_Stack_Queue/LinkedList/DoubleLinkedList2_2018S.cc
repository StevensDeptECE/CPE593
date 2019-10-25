class DoubleLinkedList2 {
private:
	class Node { // DoubleLinkedList2::Node
	public:
		int data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	DoubleLinkedList2() : head(nullptr), tail(nullptr) {}
	~DoubleLinkedList2() {

	}
	void addEnd(int v) { //O(1)
		Node* temp = new Node();
		temp->data = v;
		temp->next = nullptr;
		temp->prev = tail;
		if (tail == nullptr) {
			head = tail = temp;
		} else {
			tail->next = temp;
			tail = temp;
		}
	}
	void addStart(int v) { //O(1)
		Node* temp = new Node();
		temp->data = v;
		temp->next = head;
		temp->prev = nullptr;
		if (head == nullptr) {
			head = tail = temp;
		} else {
			head->prev = temp;
			head = temp;
		}
	}

	void removeStart() {
		if (head == nullptr)
			return;
		if (head == tail) {
      delete head;
			head = tail = nullptr;
			return;
		}
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}

	bool isEmpty() {
		return head == nullptr;
	}
	
	void removeEnd() {
		if (tail == nullptr)
			return;
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* secondToLast = tail->prev;
		delete tail;
		secondToLast->next = nullptr;

	}
  friend ostream& operator <<(ostream& s, const DoubleLinkedList2& list) {
    for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->data << ' ';
		return s;
	}
};
int main() {
	DoubleLinkedList2 list;
	list.addEnd(5);
	list.removeEnd();
	list.addStart(3);
	list.removeStart();
	for (int i = 0; i < 10; i++)
		list.addEnd(5);
	list.removeStart();
	list.removeEnd();
	cout << list << '\n';
}
