// c++ vector
//Java ArrayList

class GrowArray {
private:
	int* data; // int[] data
	uint_32t len;
	//NOT REQUIRED	uint_32t start;
	uint_32t capacity;
	void grow() {
		capacity = 3*capacity;
	}
public:
	void addEnd(); //O()??
	void addStart(); //O()??
