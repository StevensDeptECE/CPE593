class Matrix {
private:
	int rows, cols;
	double* m;
public:
	Matrix(int rows, int cols, double val) : rows(rows), cols(cols),
																					 m(new double[rows*cols]) {
		for (int i = 0; i < rows*cols; i++)
			m[i] = val;
	}
	~Matrix() {

	}
	Matrix(const Matrix& orig) = delete;
	Matrix operator =(const Matrix& orig) = delete;
  double& operator ()(int r, int c) {
		return m[r*cols + c];
	}
	
	double operator ()(int r, int c) const {
		return m[r*cols + c];
	}
	
};

int main() {
	Matrix m1(3, 4, 0.0);
	m1(1,2) = 1.5;  // Java: m1.set(1,2,1.5);
	Matrix m2(3, 4, 1.0);
  Matrix m3 = m1 + m2; // matrix addition
	cout << m3 << '\n';

	Matrix m4(4, 2, 0.5);
	m4(0,0) = 5.0;
	m4(0,2) = -1.0;
	Matrix m5 = m1 * m4;
	cout << m5;
	ifstream f("hw5.dat");
  Matrix A = Matrix::read(f);
  vector<double> B = read(A.getRows(), f);
  vector<double> x = solve(A, B);
  for (auto v : x) {
		cout << v << '\t';
	}
	cout << '\n';
}	

	
