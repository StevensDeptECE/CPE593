class HashMapLinearChaining {
private:
	vector< list<int> > table;
public:
	void computeHist() {
		int hist[10] = {0};
    for (auto e : table) {
      int num = min(e.size(), 9) ;
			hist[num]++;
		}
		// print out hist
	}
};

class HashMapLinearProbing {
private:
	vector< int > table; // 0 = empty
public:
	void add(int key) {
		int h = hash(key);
		int count = 0;
		while (table[h] != 0) {
			if (table[h] == key) {
        count = min(count, 9) ;
				hist[count]++;
				return;
			}
			h = h + 1;
			count++;
			if (h >= table.size)
				h = 0;
		}
    table[h] = key;
    count = min(count, 9) ;
  	hist[count]++;
	}

	bool contain(int key) {
    // add hist count here?
	}
	void computeHist() {
    // hist is already computed, just print    
	}
};
