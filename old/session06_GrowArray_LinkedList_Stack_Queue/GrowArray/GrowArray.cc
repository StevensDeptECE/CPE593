// c++ vector
//Java ArrayList

class GrowArray {
private:
	int*     data; // int[] data
	uint32_t len;
	//NOT REQUIRED	uint_32t start;
	uint32_t capacity;
	void grow() {
		capacity = 2*capacity;
	}
public:
	void addEnd(); //O()??
	void addStart(); //O()??
