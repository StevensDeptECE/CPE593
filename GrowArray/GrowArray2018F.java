publix class GrowArray {
	private	int capacity; // the size of the block of memory
	private int size;     // how many are used
	private int[] p;       // pointer to the block
	private void checkGrow() { // double in size!!!

	}
	
	public GrowArray() {}
	public GrowArray(int initialSize) {}
	
	public void insertEnd(int v) { //O(1)
		checkGrow();
		p[size++] = v;
	}
	public void insertStart(int v) { //O(???)
		checkGrow();
		// more work....
	}
	public void insert(int pos, int v) { //O(???)
	}
	public void removeStart() {
	}

	public void removeEnd() {
	}

	public String toString() {
		StringBuilder b = new StringBuilder( avgSizePerElement * size );
		b.append( ...);
		return b.toString();
	}
	public static void main(String[] args) {
		GrowArray b = new GrowArray();
		for (int i = 0; i < 10; i++)
			b.insertEnd(i);
		for (int i = 0; i < 10; i++)
			b.insertStart(i);
		System.out.println(b);
		for (int i = 0; i < 10; i++)
			b.removeStart();
		b.removeEnd();
		System.out.println(b);
	}
}
