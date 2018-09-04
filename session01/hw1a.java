import java.util.*;

public class hw1a {
	public static double choose(int n, int r) {
		return 0;
	}

	public static void main(String[] args) {
		int numTrials = 100000000;
		Random rnd = new Random(0);
		for (int i = 0; i < numTrials; i++) {
			int n = rnd.nextInt(501);
			int r = rnd.nextInt(n+1);
			choose(n,r);
		}
	}
}
