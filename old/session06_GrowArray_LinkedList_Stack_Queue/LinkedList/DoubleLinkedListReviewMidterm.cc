class DoubleLinkedList {
private:
	class Node {
	public:
    int val;
		Node* next;
		Node* prev;
		
	};

	Node* head;
public:
	DoubleLinkedList() : head(nullptr) {}
	~DoubleLinkedList() {

	}
	void addStart(int v) {
		if (head != nullptr) {
			Node* temp = new Node();
			temp->next = head;
			temp->prev = nullptr;
			temp->val = v;
			head->prev = temp;
			head = temp;
		} else {
			head = new Node();
			head->next = nullptr;
			head->prev = nullptr;
			head->val = v;

		}
		void addEnd(int v) {
			if (head == nullptr) {
				head = new NOde();
				head->val= v;
			  head->next = nullptr;
				head->prev = nullptr;
				return;
			}
			Node* p;
			for (p = head; p->next != nullptr; p = p->next)
				;
			// p is guaranteed to point to last element
			Node* temp = new Node();
			temp->next = nullptr;
			temp->prev = p;
			temp->val = v;
			p->next = temp;
		}
	}

};
