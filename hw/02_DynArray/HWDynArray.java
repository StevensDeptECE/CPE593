public class HWDynArray {
	private int[] p;
	private int size; // the number of elements used
	private int capacity; // the amount of memory
	private void checkGrow() {
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	}
	public HWDynArray(int initialCapacity) {

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
    		try {
			HWDynArray a = new HWDynArray(500);   // empty list with 500 elements
			int n = Integer.parseInt(args[0]);
			for (int i = 0; i < 500; i++)
				a.addEnd(i); // really fast!
		
			for (int i = 0; i < n; i++)
				a.addEnd(i); // every time you need to grow, double
		
			a.addStart(5);
		
			for (int i = 0; i < n/2; i++)
				a.removeEnd();
		
			for (int i = 0; i < n/2; i++)
				a.removeStart();
		
		
			a.removeEvens();
			System.out.println(a);
			
    		}
    		catch (NumberFormatException nfe) {
			System.out.println("Argument must be an integer value");
		}
    	}
}
