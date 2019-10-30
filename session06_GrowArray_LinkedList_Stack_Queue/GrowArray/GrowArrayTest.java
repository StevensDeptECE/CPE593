import java.util.ArrayList; // used to be Vector

public class GrowArrayTest {
	
	public static void test1(int n) {
		GrowArray a = new GrowArray();
		for (int i = 0; i < n; i++)
			a.insertEnd(i);
	}

	public void test2(int n) {
		GrowArray a = new GrowArray(n);
		for (int i = 0; i < n; i++)
			a.insertEnd(i);
	}

	public static void test3(int n) {
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < n; i++)
			a.add(i);
	}

	public static void test4(int n) {
		ArrayList<Integer> a = new ArrayList<>(n);
		for (int i = 0; i < n; i++)
			a.add(i);
	}

int main() {
	const int n = 1000000000;

	// warm up by running the function once
	test1(n);

	long t0 = System.nanoTime();
	test1(n);
	long t1 = System.nanoTime();
	System.out.println((t1-t0)*1e-9);
	
	//	test2(n);
	//	test3(n);
	// test4(n);
}
