#include <iostream>
/*
	This matrix is the efficient representation, a single block of contiguous memory

  this is the "java" way
	double[][] m = new double[rows][cols];

  double** m;
  m = new double*[rows];
  for (int i = 0; i < rows; i++)
    m[i] = new double[cols];
       cols
     a b c d
rows e f g h
     i j k m

 */
class Matrix {
private:
	uint32_t rows, cols;
	double* m;
public:
	Matrix(uint32_t rows, uint32_t cols, double defaultVal); //O(rows*cols)
	~Matrix(uint32_t rows, uint32_t cols, double defaultVal); //O(1) 
	Matrix(const Matrix& orig);
	Matrix& operator =(const Matrix& orig);
	/*
       x x x x    y y y y
	   x x x x +  y y y y
	   x x x x    y y y y

	*/
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
       if (a.rows != b.rows || a.cols != b.cols)
	     throw "UUUUUUUUUUGH!";
		// still happens!

	}
	/*
	      mxn      nxp       m x p
        a a a *    b    =   c
	    a a a      b        c
                   b

	*/
	friend Matrix operator *(const Matrix& a, const Matrix& b);

	friend ostream& operator <<(ostream& s, const Matrix& m);
	void solve
}
