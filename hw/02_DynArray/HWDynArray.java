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
    		try {
    			int n = Integer.parseInt(args[0]);
			LinkedList a = new LinkedList();
			for (int i = 0; i < n; i++)
				a.addStart(i);
        
			for (int i = 0; i < n; i++)
				a.addEnd(i);
        
			for (int i = 0; i < 3*n/2; i++)
				a.removeStart();
			for (int i = 0; i < n/2 - 5; i++)
				a.removeEnd();
			System.out.println(a);
			for (int i = 0; i < 10; i++)
				a.insert(1, i);
			System.out.println(a);
    		}
    		catch (NumberFormatException nfe) {
			System.out.println("Argument must be an integer value");
		}
    	}
}
