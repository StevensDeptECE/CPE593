import java.util.*;

public class hw1atest {
	public static double choose(int n, int r) {
		return 0;
	}
	
	public static void main(String[] args) {
		int testCases[][] = new int[][]{
			{0, 0, 1},
			
			{1, 0, 1},
			{1, 1, 1},
			
			{2, 0, 1},
			{2, 1, 2},
			{2, 2, 1},
			
			{5, 0, 1},
			{5, 1, 5},
			{5, 2, 10},

			{6, 3, 20}
		};
	
		for (int i = 0; i < testCases.length; i++) {
			int n = testCases[i][0];
			int r = testCases[i][1];
			int result = testCases[i][2];
		
			if (choose(n, r) != result) {
				System.err.println("Failed test case: choose(" + n + ", " + r + ") = " +
													 result + '\n');
			}
		}

		System.out.println("Large number tests\n");
		System.out.println(choose(52, 6));
		System.out.println(choose(52, 26));
		System.out.println(choose(150, 5));
	}
}
