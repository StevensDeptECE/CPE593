#include <iostream>
#include <string>
using namespace std;

// Predefined string object, to avoid recreation
const string EMPTY = string("");

class HashMapLinearProbing {
private:
	struct Node {
		string key;
		int val;
		Node() : key(""), val(0) {}
	};
    Node* table;
	uint32_t used;
	uint32_t size;
	uint32_t hash(const string& key) {
		uint32_t sum = 0;
		for (uint32_t i = 0; i < key.length(); i++)
		  sum = (sum * 26 + key[i]) ^ ((sum >> 13) | (sum << 19));
		return sum & size; // bitwise AND, Fast modulo for power of 2
	}
	void grow() {}
public:
// let's assume size is always a power of 2
	HashMapLinearProbing(uint32_t s) : table(new Node[s]), used(0), size(s-1){}
	
	~HashMapLinearProbing()
	{
		delete [] table;
	}

	HashMapLinearProbing(const HashMapLinearProbing& orig) = delete;
	HashMapLinearProbing& operator =(const HashMapLinearProbing& orig) = delete;


    void add(const char key[], int val) {
		if (2*used >= size)
		  grow();
		string skey(key); // build a string object (slow)
		uint32_t pos = hash(skey);
		while (table[pos].key != EMPTY) {
			pos = (pos + 1) & size; // bitwise AND, ultrafast modulo for power of 2
		}
		used++;
		table[pos].key = skey;
		table[pos].val = val;
	}

// if the key is there, put the corresponding value into val and return true
// otherwise return false
	bool get(const char key[], int& val) {
		string skey(key);
		uint32_t pos = hash(skey);
		
		while(table[pos].key != EMPTY)
		{
			if (table[pos].key == skey)
				return true;
			pos = (pos + 1) & size;
		}
		return false;
	}


};

int main() {
	HashMapLinearProbing m(16384);
	m.add("testing", 5);
	m.add("apple", 92);
	m.add("hello", 3);

	int v;
	if (m.get("hello", v)) {
		cout << v	<< '\n';
	}
}


	//HashMapLinearProbing m2 = m;
