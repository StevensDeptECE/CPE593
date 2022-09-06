#include <string>
using namespace std;

class HashMapLinearChaining {
private:
	uint32_t size;
	vector<LinkedList<string> > table;
public:
	HashMapLinearChaining(uint32_t size) : vector(size) {
		//		table = new LinkedList<string>[size];
	}
	~HashMapLinearChaining() {}
	HashMapLinearChaining(const HashMapLinearChaining& orig) = delete;
	HashMapLinearChaining& operator =(const HashMapLinearChaining& orig) = delete;q
	void add(const string& s) {

	}
	void remove(const string& s) {

	}
	bool contains(const string& s) {

	}
	void computeHistogram() {
    // generate an array of 10 elements
		//hist[0] = number of empty bins
		// hist[1] = number of bins containing 1 element
		// hist[2] = number of bins containing 2 elements...

		// hist[9] = number of bins containing 9 OR GREATER
		//		print all non-zero bins:
	}
};
