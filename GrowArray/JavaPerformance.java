import java.util.*;

public class JavaPerformance {
	public static void testArrayList(int n) {
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < n; i++)
			a.add(i);
	}

	public static void testArrayListPreallocated(int n) {
		ArrayList<Integer> a = new ArrayList<>(n);
		for (int i = 0; i < n; i++)
			a.add(i);
	}
	public static void testGrowArrayPreallocated(int n) {
		GrowArrayInt a = new GrowArrayInt(n);
		for (int i = 0; i < n; i++)
			a.add(i);
	}
	public static void main(String[] args) {
		//		testArrayList(1000);
		testGrowArrayPreallocated(1000);
		//		testArrayListPreallocated(1000);
		final int n = 10000000;
		long t0 = System.nanoTime();
		//		testArrayList(n);
		testGrowArrayPreallocated(n);
		//		testArrayListPreallocated(n);
		long t1 = System.nanoTime();
		System.out.println((t1-t0)*1e-9);
	}
}
		
class GrowArrayInt {
	private int[] data;
	private int size;
	public GrowArrayInt(int n) {
		data = new int[n];
		size = 0;
	}
	public void add(int n) {
		//		if (size >= data.length)
		//			grow();
		data[size++] = n;
	}
}
