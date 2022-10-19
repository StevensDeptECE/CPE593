class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
	  if (memory does not need to grow)
	    return;
	  
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	}
public:
	void addEnd(int v) {
		
	}

	void addStart(int v) {

	}
	void removeStart() {

	}
	
	void removeEnd() {

	}
};

int main() {
	HWDynArray a(500); // empty list, with 500 elements
    uint32_t n;
    cout << "Enter an integer: ";
    cin >> n;

	for (int i = 0; i < 500; i++)
		a.addEnd(i); // really fast!

	for (int i = 0; i < n; i++)
		a.addEnd(i); // every time you need to grow, double

	a.addStart(5);
	
	for (int i = 0; i < n/2; i++)
		a.removeEnd();

	for (int i = 0; i < n/2; i++)
		a.removeStart();

	
    a.removeEvens();
	
	cout << a << '\n';
}
