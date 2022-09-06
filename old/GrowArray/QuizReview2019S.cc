class LinkedList {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node* prev;
		Node(v, n, p) { val = v  next = n; prev=p; }
	};

	Node* head;
	Node* tail;

public:
  LinkedList() {
		head = tail = nullptr;
	}

	~LinkedList() {
		Node temp;
		for (Node* p = head; p != nullptr; ){
			Node* temp = p;
			p = p->next;
			delete temp;
		}
	}

	void addFirst(int v) {
		Node* temp  = new Node();
		temp->val = v;
		temp->prev = nullptr;
		temp->next = head;

		if (tail == null)
			tail = temp;
		else
			head->prev = temp;
		head = temp;
	}
  void addLast(int v) {
		Node* temp = new Node();
		temp->val = v;
		temp->prev = tail;
		temp->next = nullptr;
		
		if (head == nullptr)
			head = temp;
		else
			tail->next = temp;
		tail = temp;
	}

	int removeFirst() {
		Node* old = head;
		head = head->next;
		head->prev = nullptr;
		delete old;
	}
}

	class GrowArray {
	private:
		int[] data; // has data.length
		int numUsed;
		void grow() {
			int[] newdata = new int[data.length*2];
			for (int i = 0; i < data.length; i++)
				newdata[i] = data[i];
			int[] temp = data;
			data = newdata;
			free(temp);
		}
	public:
    GrowArray() {
			data = new int[1];
			numUsed = 0;
		}
		void addEnd(int v) {
			if (numUsed == data.length)
				grow();                     //1 + 1 + 1 + 2 + 1 + 1  + 4 + 1 + 1 + 1 + 1
		}
	};

//1 2 3 4 5 6 ....   n


//n    n/2    n/4    n/8 .... 1
//n(1 + 1/2 + 1/4 + 1/8 + ...) = 2n = O(n)
int main() {
	const int n = 1000000;
	GrowArray a(n);
		for (int i  =0; i < n; i++) //O(n)
			a.addEnd(i); //O(1)
