#include <string>
#include <iostream>


using namespace std;

class HashMapLinearProbing {
private:
	class Bucket {
	public:
		string key;
		int val;
		bool present;
		Bucket() { present = false; }
	};
	Bucket* table;
	uint32_t size; // white book sez: table size should be PRIME 31097
	// My advice: ignore white book
	// see: azillionmonkeys.com
	uint32_t hash(const string& key) {
		uint32_t sum = key.length();
		for (int i = 0; i < key.length(); i++) {
			sum  = (sum << 5) + (sum >> 17) + key[i];
		}

		// size = 1024  (2 to 10)  mod 1024    0...1023
    return sum & (size-1);
	}
public:
	HashMapLinearProbing(uint32_t initialSize = 1024) : size(initialSize) {
		table = new Bucket[initialSize];
	}
	~HashMapLinearProbing() {
		delete [] table;
	}

	HashMapLinearProbing(const HashMapLinearProbing& orig) : size(orig.size){
		table = new Bucket[size];
		for (int i = 0; i < size; i++)
			if (orig.table[i].present)
				table[i] = orig.table[i];
	}

	HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) {
		if (this != &orig) {
			delete [] table;
			size = orig.size;
			table = new Bucket[size];
			for (int i = 0; i < size; i++)
				if (orig.table[i].present)
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

	Bucket& operator [](const Key& key) {
    uint32_t pos = hash(key);

		while (table[pos].present) {
			if (table[pos].key == key)
				return table[pos];
			pos = (pos + 1) & (size-1); // MOD size
		}
		//		used++;  GROW if we fill more than 50%
		return table[pos];
	}
};

int main() {
	HashMapLinearProbing<string, double> stockQuotes(1024); // MUST BE POWER OF 2

	stockQuotes["AAPL"] = 170.5;
	stockQuotes["IBM"] =  142;
	stockQuotes["BIDU"] = 188.2;
	HashMapLinearProbing<string, double> stockQuotes2 = stockQuotes;

	cout << stockQuotes.get("AAPL") << "\n";
	cout << stockQuotes.get("XXX") << "\n";
	
	stockQuotes2 = stockQuotes;
	stockQuotes2 = stockQuotes2;
	
