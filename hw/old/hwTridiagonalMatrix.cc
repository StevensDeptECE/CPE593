#include <iostream>
/*

 */
class TridiagonalMatrix {
private:
	uint32_t n;
	double* m;
public:
	TridiagonalMatrix(uint32_t n, double defaultVal); //O(3n) = O(n)
	~TridiagonalMatrix(); //O(1) 
	TridiagonalMatrix(const Matrix& orig);
	TridiagonalMatrix& operator =(const TridiagonalMatrix& orig);

	friend TridiagonalMatrix operator +(const TridiagonalMatrix& a, const TridiagonalMatrix& b) {
       if (a.n != b.n)
	     throw "UUUUUUUUUUGH!";
       TridiagonalMatrix ans(a.n);
       for (int i =0; i < 3*n; i++)
         ans.m[i] = a.m[i] + b.m[i];

	}
	friend TridiagonalMatrix operator *(const TridiagonalMatrix& a, const TridiagonalMatrix& b);

	friend ostream& operator <<(ostream& s, const TridiagonalMatrix& m);
}
