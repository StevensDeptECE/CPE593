#include "Matrix.cc"

int main() {
  Matrix a(3,4,0.0);  // O(mn) = O(3*4)
  Matrix b(4,2,1.0); //O(n*p) = O(4*2);
  Matrix c = b; // make a copy O(np)
  Matrix d = a + a;  //O(mn)
  Matrix e = a * b;  //O(mnp)    O(n^3)
  b(1,1) = 5.2; // calls operator()(int,int)
  cout << b(1,2); // calls operator()(int,int)const
  e = b;
	/*
		a11 a12 a13      x           B1
		a21 a22 a23      y    =     B2
       a31 a32 a33      z           B3
	 */
  ifstream f("hw5.dat");
  Matrix A = Matrix::read(f);
  vector<double> B = read(A.getRows(), f);
  vector<double> x = solve(A, B);

	// you must print out the vector x
	
#if 0
	// not required for homework!
  Matrix L, U;
  A.LU(L, U); // LU = A
  // Ax1 = B1    Ax2 = B2    Ax3 = B3
	// just solve once, use L to compute answers


	// generalized least squares
  A.leastSquares(B);	
	
	// QR Factorization
	// PCA Principle Component Analysis
  for (auto v : x) {
    cout << v << '\t';
  }
  cout << '\n';
  

  // automatically call destructor
  //~Matrix(); //O(1)
#endif
}
