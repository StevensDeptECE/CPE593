#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Matrix {
private:
  int rows,cols;
  double* m;
  Matrix(int r, int c) : rows(r), cols(c), m(new double[r*c]) {    
  }
public:
  Matrix(int r, int c, double val) : rows(r), cols(c), m(new double[r*c]) {
    for (int i = 0; i < r*c; i++)
      m[i] = val;
  }
  ~Matrix() {
    delete [] m; //O(1)
  }
  Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double[rows*cols]) {
    for (int i = 0; i < rows*cols; i++)
      m[i] = orig.m[i]; //O(r*c)    
  }
  //copy and swap
  Matrix& operator =(const Matrix& orig) {
    Matrix copy(orig); //O(rows*cols)
    swap(m, copy.m);//O(1)
    rows = copy.rows;//O(1)
    cols = copy.cols;//O(1)
    return *this;
  }
#if 0
  double operator[](int i, int j) const {
    return ;
  }
  double& operator[](int i, int j) {
    return ;
  }
#endif
  // move constructor
  Matrix(Matrix&& orig) : rows(orig.rows),  cols(orig.cols) {
    m = orig.m;
    orig.m = nullptr;
  }

  //O(rows*cols) if they are the same O(n^2)
  friend Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols)
      throw "Bad matrix size";
    Matrix ans(a.rows,a.cols); //O(1)
    for (int i = 0; i < a.rows*a.cols; ++i)
      ans[i] = a[i] + b[i];
    return ans; //O(1)
  }

  double  operator()(int i, int j) const {
    return m[i*cols+j];
  }
  double&  operator()(int i, int j) {
    return m[i*cols+j];
  }
  friend Matrix operator *(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows)
      throw "Bad matrix size";
    Matrix ans(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i)
      for (int j = 0; j < b.cols; ++j) {
	double dot = 0;
	for (int k = 0; k < a.cols; k++)
	  dot += a(i, k) * b(k, j);
	ans(i,j) = dot;
      }
    return ans;
  }
  static Matrix read(istream& s) {
    int n;
    s >> n;
    Matrix m(n,n);
    for (int i = 0; i < n*n; i++)
      s >> m[i];
  }
  void partialPivot(int i, vector<double>& B) {
    int biggestPos = i;
    double biggest = (*this)(i,i);

    // partial pivoting
    for (int j = i; j < rows; j++) {
      if ((*this)(j,i) > biggest) {
	biggest = (*this)(j,i);
	biggestPos = j;
      }
    }
    // swap rows biggestpos,i
  }

  friend void backSubstitute(Matrix& m, vector<double>& x, vector<double>& B) {
    for (int n = rows; n > 0; n--) {
      x[n-1] = B[n-1] / m(n-1,n-1);
      for (int j = n-2; j >= 0; j--)
	B[j] -= m(j,n) *x[n-1];
  }
  
    friend vector<double> solve(Matrix& m, vector<double>& B) {
    vector<double> x;
    // rows = cols or we are DEAD
    x.reserve(rows);
    for (int i = 0; i < rows; i++) {
      partialPivot(i, B);
      for (int k = i+1; k < rows; k++) {
      double s = -m(k,i)/m(i,i);
      m(k,j) = 0; // make sure this is exactly zero!
      for (int j = i+1; j < cols; j++)
	m(k,j) += s * m(i,j); // modify remaining part of row
      }
      B[k] += s * B[i];
    }
    backSubstitute(B);
  }
	}
};

vector<double> read(int n, istream& s) {
  vector<double> B;
  B.reserve(n);
  double tmp;
  for (int i = 0; i < n; ++i) {
    s >> tmp;
    B.push_back(tmp);
  }
  return B;
}

