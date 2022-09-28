class LinkedList {
private:
	class Node {
	public:
		Node* next;
		int val;
		Node(int v, Node* n) : val(v), next(n) {}
	};

	Node* head;

	// copy constructor  (in Java, clone())
	LinkedList(const LinkedList& orig) {
		if (orig.head == nullptr) {
			head = nullptr;
			return;
		}
			
		head = new Node(orig.head->val, nullptr);
		Node* dest = head;
		for (Node* p = head->next; p != nullptr; p = p->next) {
			dest->next = new Node(p->val, nullptr);
			dest = dest->next
		}
	}

	LinkedList(const LinkedList& orig) {
    for (Node* p = orig.head; p != nullptr; p = p->next)
			addEnd(p->val);
	}
}
