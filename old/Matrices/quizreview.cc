Matrix m1(n,n, 0.0)


class Matrix {
  int rows, cols;
  double* m;
  Matrix(int rows, int cols) : rows(rows), cols(cols),
    m(new double[rows*cols]) {
  }
public:
  Matrix(int rows, int cols, double v) : rows(rows), cols(cols),
    m(new double[rows*cols]) {
     for (int i = 0; i < rows*cols; i++)
       m[i]= v;
  }

  friend Matrix operator +(const Matrix& a, const Matrix b) { //O(rows*cols)
    if (a.rows != b.rows || a.cols != b.cols)
      throw "Bad size";
    Matrix ans(a.rows,a.cols);
    for (i = 0; i < rows*cols; i++)
      ans.m[i] = a.m[i] + b.m[i];
  }

	double& operator () (int r, int c) {
    return m[r * cols + c];
	}
  Matrix transpose() const {
		Matrix ans(cols, rows);
		int i = 0;
		for (int r = 0; r < rows; r++) {
			int j = r;
			for (int c = 0; c < cols; c++, i++, j += cols)
				ans.m[j] = m[i];
		}
}

public class Matrix {
  private int rows, cols;
  private double[] m;

  public Matrix(int rows, int cols, double v) { //O(rows*cols)
    this.rows = rows;
    this.cols = cols;
    m = new double[rows*cols];
    for (int i = 0; i < rows*cols; i++)
      m[i] = v;
  }


/*
*	*	0	0	0
*	*	*	0	0
0	*	*	*	0
0	0	*	*	*
0	0	0	*	*
 n + n-1 + n-1

1       2 	0	0       0		2       1 	0	0       0
-1      1 	2	0       0		-2      3 	1	0       0
0	1	0	3	0		0	2	1	2	0
0	0	-1	1	2		0	0	3	2	1
0	0	0	-3	2		0	0	0	1	4


*/

class TriDiagonalMatrix {
private:
  int n;
  double* m;
  TriDiagonal(int n) : n(n), m(new double[3n-2]{ //O(3n) = O(n)
  }
public:
  TriDiagonal(int n, double v) : n(n), m(new double[3n-2]{ //O(3n) = O(n)
    for (int i = 0; i < 3n-2; i++)
      m[i] = v;
  }
  friend TriDiagonal operator + (const TriDiagonal& a, const TriDiagonal& b) { //O(n)
		 	TriDiagonal ans(n);
			for (int i = 0; i < 3*n-2; i++)
				ans.m[i] = a.m[i] + b.m[i];
			return ans;
		}

		/*

1   1   0   0   0       1   1   0   0   0       x   y   0   0   0
1   1   1   0   0       1   1   1   0   0       y   x   y   0   0
0   1   1   1   0       0   1   1   1   0    =  0   y   x   y   0
0   0   1   1   1       0   0   1   1   1       0   0   y   x   y
0   0   0   1   1       0   0   0   1   1       0   0   0   y   x


		 */

		
  friend TriDiagonalMatrix
  	 operator *(const TriDiagonalMatrix& a, const TriDiagonalMatrix& b) {
	 if (a.n != b.n)
	   throw "bad size";
     TriDiagonalMatrix ans(a.n);

     double dot = 0;
     for (int i = j; i < j+3; i++)
       dot += a(?,i) * b(i,j)

     for (int i = 1; i < n-1; i++) {
  			 ans(i,i-1) = a(i,i-1)*b(i-1,i-1)+ a(i,i)*b(i,i);
         ans(i,i) = a(i,i-1)*b(i-1,i) + a(i,i)*b(i,i) + a(i,i+1) * b(i+1,i); //O(1)
				 ans(i,i+1) = a(i,i) * b(i,i+1) + a(i+1,i)*b(i+1,i+1);	      
       }

  }
}

for k← 0 to m-1
  for j← 0 to p-1
    c(k,j)←0
    for i ← 0 to n-1
  	c(k,j) ← c(k,j) + a(k, i) * b(i, j)
    end
  end
end

for k← 0 to m-1
  for j← 0 to p-1
    dot ← 0
    for i ← 0 to n-1
      dot ← dot + a(k, i) * b(i, j)
    end
    c(k, j) ← dot
  end
end

		// remove the element in row2 using row1
		reducerow(row1, row2)

		s = m(row2,row1)  / m(row1,row1)
		m(row2,row1) = 0;
		for (int i = row1+1; i < n; i++)
			m(row2, i) = m(row2, i) - s * m(row1,i)



										 
