import java.util.*;

public class GoldenMeanSearch {
	private static Random r;

	static {
    r = new Random(2); // for testing, try a bunch of seeds.  If you get one that does not work, keep trying
	}

	// generate a random one-hump set of data
	public static int[] generateRandomQuadratic(int n) {
		int[] a = new int[n]; // O(n)
		int biggest = r.nextInt(n);
		final int maxVal = r.nextInt(10000);
		a[biggest] = maxVal;
		for (int i = biggest - 1; i >= 0; i--)
			a[i] = a[i+1] - r.nextInt(10);
		for (int i = biggest + 1; i < a.length; i++)
			a[i] = a[i-1] - r.nextInt(10);
		return a;
	}

	public static void print(int[] a) {
		for (int x : a) {
			System.out.print(x); System.out.print(' ');
		}
		System.out.println();
	}

	public static double PHI = (Math.sqrt(5)+1) / 2;
	public static int goldenMeanSearch(int[] a) {
		int L = 0, R = a.length - 1;
		int X,Y;
		Scanner s = new Scanner(System.in);
		int S = (int)((R - L) / PHI + 0.5);
		while (L < R) {
      X = R - S;
			Y = L + S;
			if (a[X] > a[Y]) {
				R = Y;
				Y = X;
				S = (int)((R - L) / PHI + 0.5);
				X = R-S;
			} else {
				L = X;
				X = Y;
				S = (int)((R - L) / PHI + 0.5);
				Y = L+S;
			}
			System.out.println(X + ", " + Y);
			s.next();
		}
		return L;
	}
	
	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		int[] x = generateRandomQuadratic(n);
		print(x);
		System.out.println(goldenMeanSearch(x));
	}
	
}
