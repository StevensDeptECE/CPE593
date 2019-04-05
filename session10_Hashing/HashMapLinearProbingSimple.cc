#include <string>
#include <iostream>
using namespace std;
const string EMPTY = "";

class HashMapLinearProbing {
private:
	class Bucket {
	public:
		string key;
		double val;
		Bucket() : key() {} // notice: val not initialized, random!
	};
	Bucket* table;
	uint32_t size; // white book sez: table size should be PRIME 31097
	uint32_t used;
	// My advice: ignore white book
	// see: azillionmonkeys.com
	uint32_t hash(const string& key) {
		uint32_t sum = key.length();
		for (int i = 0; i < key.length(); i++) {
			sum  = (sum << 5) + (sum >> 17) + key[i];
		}

		// size = 1024  (2 to 10)  mod 1024    0...1023
    return sum & (size-1); // only works with power of 2
	}
#if 0
	uint32_t hash(uint32_t key) {


	}
#endif

	void grow() {
    Bucket* old = table;
		table = new Bucket[2*size];
		for (uint32_t i = 0; i < size; ++i)
			if (old[i].key != EMPTY)
				table[hash(old[i].key)] = old[i];
		delete [] old;
		size = 2*size;
	}
public:
	HashMapLinearProbing(uint32_t initialSize = 1024)
		: size(initialSize), used(0) {
		table = new Bucket[initialSize];
	}
	~HashMapLinearProbing() {
		delete [] table;
	}

	HashMapLinearProbing(const HashMapLinearProbing& orig) : size(orig.size){
		table = new Bucket[size];
		for (int i = 0; i < size; i++)
			if (orig.table[i].key != EMPTY)
				table[i] = orig.table[i];
	}

	HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) {
		if (this != &orig) {
			delete [] table;
			size = orig.size;
			table = new Bucket[size];
			for (int i = 0; i < size; i++)
				if (orig.table[i].key != EMPTY)
					table[i] = orig.table[i];
		}
		return *this;
	}
#if 0	
	HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) {
		HashMapLinearProbing copy(orig);
		size = copy.size;
		swap(table, copy.table);
	}
#endif

	double& operator [](const string& key) {
    uint32_t pos = hash(key);

		while (table[pos].key != EMPTY) {
			if (table[pos].key == key)
				return table[pos].val;
			pos = (pos + 1) & (size-1); // MOD size
		}
		used++;  //GROW if we fill more than 50%
		if (used * 1.3 > size)
			grow();
		return table[pos].val;
	}
};

int main() {
	HashMapLinearProbing stockQuotes(1024); // MUST BE POWER OF 2

	stockQuotes["AAPL"] = 170.5;
	stockQuotes["IBM"] =  142;
	stockQuotes["BIDU"] = 188.2;
	HashMapLinearProbing stockQuotes2 = stockQuotes;

	cout << stockQuotes["AAPL"] << '\n';
	//	cout << stockQuotes.get("AAPL") << "\n";
	//	cout << stockQuotes.get("XXX") << "\n";
	
	//stockQuotes2 = stockQuotes;
	//	stockQuotes2 = stockQuotes2;
	
}
