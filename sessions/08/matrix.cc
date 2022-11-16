class Matrix {
private:
	uint32_t rows, cols;
  double* m;
public:
	Matrix(uint32_t rows, uint32_t cols, double v) : rows(rows), cols(cols), m(new double[rows*cols]) {
		for (int i = 0; i < rows * cols; i++)
			m[i] = v;
	}
	~Matrix() {
		delete [] m;
	}
	Matrix(const Matrix& orig) = delete;
	Matrix& operator =(const Matrix& orig) = delete;

	/*         c
		   0  1    2   3
		0 a11 a12 a13 a14
	r	1 a21 a22 a23 a24
		2 a31 a32 a33 a34
	 */
	double operator ()(uint32_t r, uint32_t c) const {
		return m[r*cols + c];
	}
	double& operator ()(uint32_t r, uint32_t c) {
		return m[r*cols + c];
	}
	/*
		1 a a a a a
		a a a a a a
		a a a a a a
		6 a a a a a


		6 a a a a a
		a a a a a a
		a a a a a a
		1 a a a a a		

		6 a a a    B 
		0 4 a a =  B
		0 0 3 a    B
		0 0 0 4    B


	*/



	
	// Ax = B solve for x
	void solve(vector<double>& x, const vector<double>& B) {
		if (rows != cols)
			throw "underdetermined or overdetermined";
		for (uint32_t i = 0; i < cols-1; i++) {
			double big = (*this)(i,i);
			uint32_t bigrow = i;
			for (uint32_t j = i+1; j < rows; j++)
				if ((*this)(i,j) > big) {
					big = (*this)(i,j);
					bigrow = j;
				}
			if (bigrow > i) { // swap row i with bigrow
				for (uint32_t k = i; k < cols; k++)
					swap(m(bigrow,k), m(i,k));
				swap(B[bigrow], B[i]);
			}
			// row reduction
			for (uint32_t j = i+1; j < rows; j++) {
				double s = -(*this)(j,i ) /(*this)(i,i );
				(*this)(j,i) = 0; // set the element directly to zero
				for (uint32_t k = i+1; k < cols; k++)
					(*this)(j,k) += s * (*this)(i,k);
				B[j] += s * B[i];
			}
		}
		// end row reduction
		//back substitution
		// left as an exercise...
			
	}
};

// A*B  first calculate  transpose(B)
// A*Bt
