#include <iostream>

using namespace std;

// Dov's preferred method
class Matrix {
private:
	uint32_t rows, cols;
	double* m;
public:
	Matrix(uint32_t rows, uint32_t cols)
		: rows(rows), cols(cols), m(new double[rows*cols]) {
	}
};

//Java's method
class Matrix2 {
private:
	uint32_t rows, cols;
	double** m;
public:
	Matrix(uint32_t rows, uint32_t cols)
		: rows(rows), cols(cols), m(new double*[rows]) {
		for (uint32_t i = 0; i < rows; i++)
			m[i] = new double[cols];

	}


int main() {
	int n;
	cin >> n;
	int x[n]; // C++ 11 x = new int[n]; ... delete [] x;
	int a[3][4] = {0};
	a[1][2] = 3;

	int* p = &a[0][0];
	cout << *p++; // 0
	cout << *p++; // 0
	cout << *p++; // 0
	cout << *p++; // 0 // first row
	cout << *p++; // 0
	cout << *p++; // 0
	cout << *p++; // 3 // 3rd element of 2nd row
}
