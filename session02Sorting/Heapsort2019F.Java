public class Heapsort2019F {
	public static void makesubheap(int x[], int i) {
		int left = 2*i+1, right = 2*i+2;
		if (left >= x.length)
			return;
	  if (right >= x.length) {
			if (x[left] > x[i]) {
				int temp = x[i];
				x[i] = x[left];
				x[left] = temp;
				return;
			}
		}
		// x[i] has left AND right child
		if (x[left] > x[right]) {
			if (x[left] > x[i]) {
				int temp = x[i];
				x[i] = x[left];
				x[left] = temp;
				makesubheap(x, left);
			}
		} else {
			if (x[right] > x[i]) {
				int temp = x[i];
				x[i] = x[right];
				x[right] = temp;
				makesubheap(x, right);
			}
		}
	}
	
	public static void makeheap(int[] x) {
		for (int i = x.length/2; i > 0; i--) {
			makesubheap(x, i);
		}
	}
	public static void fixheap(int[] x, int i) {
		makesubheap(x, 0);
	}
	public static void heapsort(int[] x) {
		makeheap(x);
		for (int i = x.length-1; i > 0; i--) {
			int temp = x[0];
			x[0] = x[i];
			x[i] = temp;
			fixheap(x, i);
		}	
	}
	
	public static void main(String[] args) {
		int [] x = { 1, 2, 3, 4, 5, 6, 7, 8};
		heapsort(x);
		for (int i = 0; i < x.length; i++)
			System.out.print(x[i] + " ");
		System.out.println();
	}

}
