class LinkedList {
private:
	class Node { // LinkedList::Node
	public:
		int value;
		Node* next;
	};

	Node* head; // LinkedList contains a pointer to a head node
public:
	LinkedList() {
		head = nullptr;
	}
	void addStart(int v) {
		Node* temp = new Node();
		temp->value = v;
		temp->next = head;
		head = temp;
	}

	void removeStart() {
		Node* temp = head;
		head = head ->next;
		delete temp;
	}

	void removeEnd() {
		Node* p = head;
		//Check for error condition:		if (p == null)
		Node* q = p->next;
		if (q == nullptr) {
			p->next = nullptr;
			return;
		}
		while (q->next != nullptr) {
			p = q;
			q = q->next;
		}
		delete q;
		// q points to last node p points to the 2nd last Node
		p->next = nullptr;
		
	}
