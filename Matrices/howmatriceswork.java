public class howmatriceswork {
	public static void f(int n) {
		double [][] a = new double[n][n];

	}
	public static void main(String[] args) {
		// x is stored as an array of references
		// to array of double
		double x[3][4] = {
			{1, 2, 5, 6},
			{2, -1, 3, 8},
			{3, 1, 5, 2}
		};

		x[0][2] = 3;
	}
