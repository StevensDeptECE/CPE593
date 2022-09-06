public class HWGrowArray {
	private int[] p;
	private int size; // the number of elements used
	private int capacity; // the amount of memory
	private void checkGrow() {
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	}
	public HWGrowArray(int initialCapacity) {

	}
	public void addEnd(int v) {
		
	}

	public void addStart(int v) {

	}
	public void removeStart() {

	}
	
	public void removeEnd() {

	}
	

	public static void main(String[] args) {
		HWGrowArray a = new HWGrowArray(500); // empty list, with 500 elements

		for (int i = 0; i < 500; i++)
			a.addEnd(i); // really fast!
		
		for (int i = 0; i < 10000000; i++)
			a.addEnd(i); // every time you need to grow, double
		
		a.addStart(5);
		// 5 0 1 2 3 4 5 6 7 8....   499 0 1 2 3 4 5 6 .... 999999	
		
		for (int i = 0; i < 10000; i++)
			a.removeEnd();
		
		for (int i = 0; i < 10000; i++)
			a.removeStart();
		
		// 10000 10001 10002 10003 10004 10005 .... .... 998999	
		
		a.removeEvens();
		System.out.println(a); // use StringBuilder, not String
	}
}
