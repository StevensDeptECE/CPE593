// in Java this is called ArrayList
// in C++ this is called vector

public class GrowArray2 {
	private	int[] data;
	private	int used;
	//	int capacity; = data.length
	void grow() {
		// DOUBLE EACH TIME!!!
	}
	private void checkGrow() {
		if (used == capacity)
			grow();
	}
	public void addEnd(int v) { //O(1)
		checkGrow();

	}
	public void addStart(int v); // O(n)

	public 	void removeEnd() { //O(1)

	}
	public String toString() {
		// int = -2100000000
		StringBuilder b = new StringBuilder(11*data.length);
		for (int i = 0; i < data.length; i++)
			b.append(data[i]).append(" ");

	}
	
};
