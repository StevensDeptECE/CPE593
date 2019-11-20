public class Matrix2019F {
  private int rows, cols;
  private double[] m;

  public Matrix2019F(int r, int c) {
    rows = r; cols = c;
    m = new double[r*c];
  }

  public Matrix2019F(Scanner s) {
    int n = s.nextInt();
    rows = n; cols = n;
    m = new double[n*n];
    for (int i = 0; i < n*n; i++)
      m[i] = s.nextDouble();
  }

  
  public double get(int r, int c) {
    return m[r * cols + c];
  }

  public void set(int r, int c, double v) {
    m[r * cols + c] = v;
  }

  private void rowReduce(int i) {

  }

  private void partialPivot(int n) {
  }

  public double[] solve(double [] B) {
    return null; //TODO: write this
  }

  public Matrix2019F mult(Matrix2019F b) {
    return null; // TODO: implement
  }
  


}

/*

 x  x  0  0  0  0
 x  x  x  0  0  0
 0  x  x  x  0  0
 0  0  x  x  x  0
 0  0  0  x  x  x
 0  0  0  0  x  x

 */
class TriDiagonal {
  private int n;
  private double[] m;

  public TriDiagonal(int n) {
    this.n = n;
    m = new double[3*n-2];
  }
  public double get(int r, int c) {
    if (Math.abs(r-c) > 1)
      return 0;
    //    return m[3*r + (c+1-r)
    return m[2*r + c];
  }

}


/*

 x  0  0  0  0  0
 0  x  0  0  0  0
 0  0  x  0  0  0
 0  0  0  x  0  0
 0  0  0  0  x  0
 0  0  0  0  0  x

 */
class Diagonal {
  private int n;
  private double[] m;

  public TriDiagonal(int n) {
    this.n = n;
    m = new double[n];
  }
  public double get(int r, int c) {
    if (r != c)
      return 0;
    return m[r];
  }

}
