#include <vector>
constexpr double INF = std::numeric_limits<double>::infinity();
class Matrix {
private:
	uint32_t rows, cols;
	double* m;

public:
	// Gauss-Jordan with partial pivoting.  Full pivoting = 200 points
	vector<double> solve(const vector<double> B);
  friend Matrix operator	*(const Matrix& a, const Matrix& b);
	void LUFactorize(Matrix& L, Matrix& U);
	gramSchmidt()
};

/*
	Same for Tridiagonal and Diagonal Matrices

 */

