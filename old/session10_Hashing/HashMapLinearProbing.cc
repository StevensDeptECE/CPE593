template<typename Key, typename Value>
class HashMapLinearProbing {
private:
	class Bucket {
	public:
		Key key;
		Value val;
		bool present;
		Bucket() { present = false; }
	};
	Bucket* table;
	uint32_t size;
	uint32_t hash(const Key& key) {
    
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

	operator [](const Key& key) {


	}
};

int main() {
	HashMapLinearProbing<string, double> stockQuotes;

	stockQuotes["AAPL"] = 170.5;
	stockQuotes["IBM"] =  142;
	stockQuotes["BIDU"] = 188.2;
	HashMapLinearProbing<string, double> stockQuotes2 = stockQuotes;

	cout << stockQuotes.get("AAPL") << "\n";
	cout << stockQuotes.get("XXX") << "\n";
	
	stockQuotes2 = stockQuotes;
	stockQuotes2 = stockQuotes2;
	
