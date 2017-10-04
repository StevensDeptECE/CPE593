class LinkedList {
private:
	class Node { // LinkedList::Node
	public:
    // inner class automatically has a pointer o the outer class
		int val;
		Node* next;
		Node(int v, Node* next) : val(v), next(next) {}
	};

  Node* head;

	//object.   pointer->
	Node* tail() { //O(n)
		Node* p = head;
		if (p == nullptr)
			return nullptr;
		for ( ; p->next != nullptr; p = p->next)
			;
		return p;
	}

public:
	LinkedList() { //O(1)
		head = nullptr;
	}
	void addStart(int v) { //O(1)
		head =  new Node(v, head);
	}

	public void addEnd(int  v) {
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		tail()->next = new Node(v, nullptr);
	}
	
};

int main() {
	LinkedList list1;
	list1.addStart(5);
		
}

