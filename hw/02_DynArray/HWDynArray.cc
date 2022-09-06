class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
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
	GrowArray a(500); // empty list, with 500 elements

	for (int i = 0; i < 500; i++)
		a.addEnd(i); // really fast!

	for (int i = 0; i < 100000; i++)
		a.addEnd(i); // every time you need to grow, double

	a.addStart(5);
	// 5 0 1 2 3 4 5 6 7 8....   499 0 1 2 3 4 5 6 .... 99999	

	for (int i = 0; i < 90500; i++)
		a.removeEnd();

	for (int i = 0; i < 9000; i++)
		a.removeStart();

	// 999 1000 1001 1002 1003 1004 1005 .... .... 1999	

  a.removeEvens();
	// 999 1001 1003 ... 1999
  // keep 2 indices (i,j)
	// first index goes through the array
	// second advances only when you have one you want
	/*
		example
           j
     5 4 3 2 1
     5 3 1 2 1
             i
    j = 0
    for i = 0 to 4
     if want a[i]
      a[j++] = a[i]
     end
    end
	 */

	
	cout << a << '\n';
}
