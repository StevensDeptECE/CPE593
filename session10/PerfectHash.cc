class PerfectHash {
private:
	constexpr int EMPTY = 0;
	class HashTable {
	public:
		int size;
		int* vals;
		HashTable(int s) : size(s), vals(new int[s]) {
			for (int i = 0; i < s; i++)
				vals[i] = EMPTY;
		}
	};
	HashTable* table;
	
};
