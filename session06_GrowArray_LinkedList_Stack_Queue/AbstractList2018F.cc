class List {
public:
	void insert(int i, int val);
	void insertEnd(int val);
	void insertStart(int val);
	void removeStart();
	void removeEnd();
	void remove(int pos);
	uint32_t size() const;
	int get(int pos);
	void set(int pos, int val);
};
