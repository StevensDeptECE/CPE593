#include <iostream>
#include <cstring>

class DiagonalMatrix {
private:
	int n;
	double* m;
	DiagonalMatrix(int n) : n(n), m(new double[n]) { //O(n)
	}
	
public:
	DiagonalMatrix(int n, double v) : n(n), m(new double[n]) { //O(n)
		for (int i = 0; i < n; i++)
			m[i] = v;
	}
	//destructor
	~DiagonalMatrix() { //O(1)
		delete [] m;
	}
	//copy constructor
	DiagonalMatrix(const DiagonalMatrix& orig) : //O(n)
		n(orig.n), m(new double[orig.n]) {
		memcpy(m, orig.m, n*sizeof(double));
	}
  DiagonalMatrix& operator =(DiagonalMatrix orig) { //O(n)
		n = orig.n;
		swap(m, orig.m);
		return *this;
	}

	// move constructor (not required but makes return by value or copy a temp faster)
	DiagonalMatrix(DiagonalMatrix&& orig) { //O(1)
		n = orig.n;
		m = orig.m;
		orig.m = nullptr;
	}
	/*
		2 0 0 0      3 0 0 0     6  0  0  0
		0 3 0 0  *   0 5 0 0  =  0  15 0  0 
    0 0 4 0      0 0 1 0     0  0  4  0
    0 0 0 1      0 0 0 -2    0  0  0  -2
	 */
	friend DiagonalMatrix operator *(const DiagonalMatrix& a,
																	 const DiagonalMatrix& b) { //O(n)
		DiagonalMatrix ans(n); //O(1) NOT INITIALIZED! Danger, danger!
		for (int k = 0; k < n; k++) { // O(n)
			ans.m[k] = a.m[k] * b.m[k];
		}
		return ans;
	}
};

/*
	Gram-Schmidt

  1  2 
  1  1

length of column 1 = sqrt(1*1 + 1*1) = sqrt(2)
length of column 2


	sqrt(2)/2    
	sqrt(2)/2    


  (2,1) -    (sqrt(2)*2 +sqrt(2)*1)/(1)(sqrt(2)/2, sqrt(2)/2)
        -  3sqrt(2)*(sqrt(2)/2, sqrt(2)/2)
				- 3 (2/2, 2/2) = (3,3)

  (1, -1)

normalize (divide by magnitude)

 */




int main() {
	DiagonalMatrix a(5, 2.0);
	DiagonalMatrix b(a); // copy
	DiagonalMatrix c = a; // copy
	a = c; // wipe out a, then copy c into a
}
