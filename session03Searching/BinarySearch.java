import java.util.*;

public class BinarySearch {
	private static Random r;

	static {
    r = new Random(0); // for testing, try a bunch of seeds.  If you get one that does not work, keep trying
	}
	
	public static int[] generateRandom(int n) {
		int[] a = new int[n]; // O(n)
		for (int i = 0; i < n; i++)
			a[i] = r.nextInt(n);
		return a;
	}

	public static void print(int[] a) {
		for (int x : a) {
			System.out.print(x); System.out.print(' ');
		}
	}
	// return either -1 (not  found) or position within the array
	public static int binarySearch(int[] x, int target) {
    int L = 0, R = x.length-1;
		
		while (L < R) {
			int g = (L+R) / 2;
			if (x[g] < target  ) {
				L = g+1;
			} else if (x[g] > target) {
        R = g-1;
			} else {
        return g;
			}
		}
		//		if (x[L] == target)
		return -1;
	}

	// return either -1 (not  found) or position within the array
	public static int binarySearch2(int[] x, int target) {
    int L = 0, R = x.length-1;
    if (target < x[L] || target > x[R])
			return -1;
		while (L < R) {
			int g = (L+R) / 2;
			if (x[g] < target  ) {
				L = g+1;
			} else if (x[g] > target) {
        R = g-1;
			} else {
        return g;
			}
		}
		//		if (x[L] == target)
		return -1;
	}


	
	public static void main(String[] args) {

		int n = Integer.parseInt(args[0]);
		int[] x = generateRandom(n);
		Arrays.sort(x);
		print(x);
		Scanner s = new Scanner(System.in);
		while (s.hasNext()) {
			int target = s.nextInt();
  		System.out.println(binarySearch(x, target));
		}

	}

}
