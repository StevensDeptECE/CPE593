public class Matrix {
	private	int rows, cols;
	private	double[] m;

	// Gauss-Jordan with partial pivoting.  Full pivoting = 200 points
	public double[] solve(double[] B) {
		double x = Double.POSITIVE_INFINITY;
		double w = 1.0e+100;
  }
	public Matrix mult(Matrix b) {


	}
	public void LUFactorize(Matrix L, Matrix U);
	public abstract void gramSchmidt();
}
