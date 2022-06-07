import java.util.*;

public class hw1 {
	// don't implement this, redo it the smart way
	private static double fact(int n) { return 0; }

	static double[][] memo = new double[101][101];
	private static Random rng = new Random(0);
	// do memoization using 2d table
	public static double choose(int n, int r) {

		// Don't compute it this way! Be smarter!
		return fact(n) / (fact(r) * fact(n-r));
	}

	// write your answer this way instead, way faster!
  //choose(7,3) = fact(7) / (fact(3)*fact(4)) = 7 * 6 * 5 / ( 3 * 2 * 1)
	// choose(8, 2) = 8 * 7 / (2*1) = 8*7*6*5*4*3 / 6 * 5 * 4 * 3 * 2 * 1

	// cancel with whichever is bigger: n-r > r
	

	public static void main(String[] args) {
		final int numTrials = 100000000; // 10^8

		double s = 0;
		int n, r;
		
		for (int i = 0; i < numTrials; i++) {
			n = Math.abs(rng.nextInt(100));
			if (n == 0)
				n = 1;
			r = Math.abs(rng.nextInt(n));
		  s += choose(n, r);
	  }
		System.out.println(s);
	}
}
	
