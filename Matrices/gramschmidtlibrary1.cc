#include <iostream>
using namespace std;

/* ----------------------- norm ----------------------- */
/*  Given an array and its length, this function 
    computes the 2-norm of the array.
    
    Input variables:
        x     : pointer to array for which the 2-norm should
                 be computed.
        length: number of entries in x.

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.      */

double norm (const double x[], int length) {
	double sum = 0;
	int length5 = length % 5;
	int i;
	for(i = 0; i < length5; i++) {
		sum += x[i] * x[i];
	}
	for(; i < length; i += 5) {
		sum += x[i] * x[i] + x[i + 1] * x[i + 1] + x[i + 2] * x[i + 2]
			+ x[i + 3] * x[i + 3] + x[i + 4] * x[i + 4];
	}
	return sqrt(sum);
}

/* ----------------------- vec_copy ----------------------- */
/*  Given two arrays of the same length and their length, 
    this function stores the values from the first array
    in the second array.
    
    Input variables:
        x     : pointer to array whose entries are to be
                 copied.
        y     : pointer to array in which the components
                 of x are to be stored.
        length: number of entries in x and in y.

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.          */

void vec_copy (const double x[], double * y, int length) {
	int length5 = length % 5;
	int i;
	for(i = 0; i < length5; i++) {
		y[i] = x[i];
	}
	for(; i < length; i += 5) {
		y[i] = x[i];
		y[i + 1] = x[i + 1];
		y[i + 2] = x[i + 2];
		y[i + 3] = x[i + 3];
		y[i + 4] = x[i + 4];
	}
}


/* ------------------- partialvec_copy ------------------- */
/*  Given two arrays, the length of the second array, and
    an index this function stores the values from the
    subarray x[index : index + length] in the array
    y[0 : length].
    
    Input variables:
        x     : pointer to array whose entries are to be
                 copied.
        y     : pointer to array in which the components
                 of x are to be stored.
        length: number of entries in y.
        index : starting index of subarray of x to be
                copied to y.

    Example: Suppose x is a pointer to the array 
    {1, 2, 3, 4, 5}, y is a pointer to the array {0, 0, 0}, 
    length = 3, and index = 2. Then after executing
    partialvec_copy(x, y, 3, 2), the array pointed to by 
    y is now {3, 4, 5}.                         

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.         */

void partialvec_copy (double * x, double * y, int length, int index) {
	int length5 = length % 5;
	int i;
	for(i = 0; i < length5; i++) {
		y[i] = x[i + index];
	}
	for(; i < length; i += 5) {
		y[i] = x[i + index];
		y[i + 1] = x[i + index + 1];
		y[i + 2] = x[i + index + 2];
		y[i + 3] = x[i + index + 3];
		y[i + 4] = x[i + index + 4];
	}
}


/* ----------------------- scalar_div ----------------------- */
/*  Given two arrays of the same length, their length, and a
    scalar value this function divides the values from the 
    first array by the scalar value and stores the computed
    number in the second array.
    
    Input variables:
        x     : pointer to array whose components are to be
                 divided by r and stored in second array, y.
        r     : scalar used in division.
        length: number of entries in x and in y.
        y     : pointer to array in which the components
                 of x are to be stored.


    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.            */

void scalar_div (const double x[], double r, int length, double * y) {
	int length5 = length % 5;
	int i;
	for(i = 0; i < length5; i++) {
		y[i] = x[i]/r;
	}
	for(; i < length; i += 5) {
		y[i] = x[i]/r;
		y[i + 1] = x[i + 1]/r;
		y[i + 2] = x[i + 2]/r;
		y[i + 3] = x[i + 3]/r;
		y[i + 4] = x[i + 4]/r;
	}
}


/* ----------------------- scalar_sub ----------------------- */
/*  Given two arrays of the same length, their length, and a
    scalar value this function multiplies the values from the 
    first array by the scalar value and then subtracts the 
    computed components from the components the second array.
    
    Input variables:
        x     : pointer to array whose components are to be
                 multiplied by r then subtracted from the
                 components of the second array, y.
        r     : scalar used in multiplication.
        length: number of entries in x and in y.
        y     : pointer to array in which the components
                 of x are to be stored.


    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.            */

void scalar_sub (const double x[], double r, int length, double * y) {
	int length5 = length % 5;
	int i;
	for(i = 0; i < length5; i++) {
		y[i] -= r * x[i];
	}
	for(; i < length; i += 5) {
		y[i] -= r * x[i];
		y[i + 1] -= r * x[i + 1];
		y[i + 2] -= r * x[i + 2];
		y[i + 3] -= r * x[i + 3];
		y[i + 4] -= r * x[i + 4];
	}
}


/* --------------------- partialscalar_sub --------------------- */
/*  Given two arrays, the length of the second array, a scalar 
    value, and an index, this function multiplies the values 
    starting at the given index from the first array by the 
    scalar value and then subtracts the computed components from 
    the components the second array.
    
    Input variables:
        x     : pointer to array whose components are to be
                 multiplied by r then subtracted from the
                 components of the second array, y.
        r     : scalar used in multiplication.
        length: number of entries in y.
        index : 
        y     : pointer to array in which the components
                 of x are to be stored.

    Example: Suppose x is a pointer to the array 
    {1, 2, 3, 4, 5}, y is a pointer to the array {0, 0, 0}, 
    length = 3, r = -1, and index = 2. Then after executing
    partialscalar_sub(x, -1, 3, 2, y), the array pointed to 
    by y is now {-3, -4, -5}. 

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.               */

void partialscalar_sub (double * x, double r, int length, 
                                              int index, double * y) {
    int i, length5;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        y[i + index] -= r * x[i];
    }
    for(; i < length; i += 5) {
        y[i + index] -= r * x[i];
        y[i + index + 1] -= r * x[i + 1];
        y[i + index + 2] -= r * x[i + 2];
        y[i + index + 3] -= r * x[i + 3];
        y[i + index + 4] -= r * x[i + 4];
    }
}


/* --------------------- dot_product --------------------- */
/*  Given two arrays of the same length and their length, 
    this function returns the dot product of the two 
    arrays.
    
    Input variables:
        x     : pointer to first array.
        y     : pointer to second array.
        length: number of entries in x and in y.

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.         */

double dot_product (double * x, double * y, int length) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        sum += x[i] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i] * y[i] + x[i + 1] * y[i + 1] + x[i + 2] * y[i + 2]
                           + x[i + 3] * y[i + 3] + x[i + 4] * y[i + 4];
    }

    return sum;
}


/* ------------------ partialdot_product ------------------ */
/*  Given two arrays of the same length, their length, and
    an index this function returns the dot product of the 
    two subarrays x[index : length] and y[index : length].
    
    Input variables:
        x     : pointer to first array.
        y     : pointer to second array.
        length: number of entries in x and in y.
        index : starting index for subarrays.

    Example: Suppose x is a pointer to the array 
    {1, 2, 3, 4}, y is a pointer to the array {5, 6, 7, 8}, 
    length = 4, and index = 2. Then the value returned by
    executing partialdot_product(x, y, 4, 2) is 53, which
    is computed by
        x[2] * y[2] + x[3] * y[3] = 3 * 7 + 4 * 8
                                  = 21 + 32
                                  = 53.

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.          */

double partialdot_product (double * x, double * y, int length, int index) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = index; i < length5; i++) {
        sum += x[i] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i] * y[i] + x[i + 1] * y[i + 1] + x[i + 2] * y[i + 2]
                           + x[i + 3] * y[i + 3] + x[i + 4] * y[i + 4];
    }

    return sum;
}


/* -------------------- subdot_product -------------------- */
/*  Given two arrays, the length of the second array, and
    an index this function returns the dot product of the 
    two subarrays x[index : index + length] and 
    y[0 : length]. It is necessary that index + length is
    at most the length of the first array.
    
    Input variables:
        x     : pointer to first array.
        y     : pointer to second array.
        length: number of entries in y.
        index : starting index for subarray of x.

    Example: Suppose x is a pointer to the array 
    {1, 2, 3, 4, 5}, y is a pointer to the array 
    {-1, -2, -3}, length = 3, and index = 2. Then the value 
    returned by executing subdot_product(x, y, 3, 2) is 53, 
    which is computed by
            x[2] * y[0] + x[3] * y[1] + x[4] * y[2] 

          =  3   *  -1  +  4   *  -2  +  5   *  -3

          = -    3      -      8      -      15

          = -26.

    Features: This implementation has time complexity 
    O(length) and requires O(1) additional memory.          */

double subdot_product (double * x, double * y, int length, int index) {
    int i, length5;
    double sum = 0;

    length5 = length % 5;

    for(i = 0; i < length5; i++) {
        sum += x[i + index] * y[i];
    }
    for(; i < length; i += 5) {
        sum += x[i + index] * y[i] + x[i + index + 1] * y[i + 1] 
                                   + x[i + index + 2] * y[i + 2]
                                   + x[i + index + 3] * y[i + 3]
                                   + x[i + index + 4] * y[i + 4];
    }

    return sum;
}

/*
  Given a matrix A of dimension m by n, this algorithm 
    computes a QR decomposition of A, where Q is a unitary 
    m by n matrix and R is a n by n upper triangular matrix
    and A = QR.    
    
    Input variables:
        a   : pointer to array of arrays, the ith array of
                which should correspond to the ith column of the 
                matrix A. During the algorithm, the columns of Q 
                will replace the columns of A.
        r   : pointer to array of arrays in which the ith 
                column of the upper triangular matrix R will be 
                stored in the ith subarray of r.
        m   : number of columns in A.
        n   : number of rows in A.
        thin: TRUE  => thin QR factorization computed
              FALSE => full QR factorization computed
    Features: This implementation has time complexity O(m n^2)
    and requires O(1) additional memory.
    Remarks: Due to the nature of the problem, if A is nearly
    rank-deficient then the resulting columns of Q may not
    exhibit the orthogonality property.
*/
void gramSchmidt (double* a, double ** r, int m, int n, bool full) {
	double anorm, tol = 10e-7;

	for(int i = 0; i < n; i++) {
		r[i][i] = norm(a[i], m);                  // r_ii = ||a_i||

		if(r[i][i] > tol) {
			scalar_div(a[i], r[i][i], m, a[i]);   // a_i = a_i/r_ii
		}
        else if(i == 0) { // set a[0] = [1 0 0 ... 0]^T
            a[i][0] = 1;
            for(j = 1; j < m; j++) {
                a[i][j] = 0;
            }
        }
        else{ // need to choose a_i orthogonal to < a_1, ... a_{i-1} >
            for(j = 0; j < m; j++) {
                a[i][j] = -a[0][i] * a[0][j];
            }
            a[i][i] += 1;

            for(j = 1; j < i; j++) {
                scalar_sub(a[j], a[j][i], m, a[i]);
            }

            anorm = norm(a[i], m);
            scalar_div(a[i], anorm, m, a[i]);
        }

        for(j = i+1; j < n; j++) {
            r[j][i] = dot_product(a[i], a[j], m); // r_ij = a_i*a_j
            scalar_sub(a[i], r[j][i], m, a[j]);   // a_j -= r_ij a_i
        }
    }

    /* if full QR factorization requested, we choose remaining 
       columns of Q so that the m columns of Q form an 
       orthonormal set                                          */
    if(full) {
        for(; i < m; i++) {
            for(j = 0; j < m; j++) {
                    a[i][j] = -a[0][i] * a[0][j];
                }
                a[i][i] += 1;
    
                for(j = 1; j < i; j++) {
                    scalar_sub(a[j], a[j][i], m, a[i]);
                }
    
                anorm = norm(a[i], m);
                scalar_div(a[i], anorm, m, a[i]);
        }
    }
}

void print(const char msg[], const double**a, int m, int n) {
	cout << msg << '\n';
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%9.6lg ", a[j][i]);
		}
		cout << '\n';
	}
	cout << '\n';
}

int main () {
	int i, j, n, m, q_n, r_m;
	bool full;

	/* let user set the dimension of matrix A */
	cout << "Enter the dimension m (where A is a m by n matrix): ";
	cin >> m;
	cout << "Enter the dimension n (where A is a m by n matrix): ";
	cin >> n;
	
	if(m != n) {
		/* check if m < n */
		if(m < n) {
			printf("For a successful factorization, this implementation "
						 "requires n <= m.\nTerminating program.\n");
			return 0;
		}
		/* let user choose either full or thin QR factorization */
		cout << "Enter either 0 to compute a thin QR factorization"
				 << endl;
		cout << "          or 1 to compute a full QR factorization: ";
		cin >> full;
	}
	else { // else m == n so full and thin QR factorization are identical */
		full = 1;
	}

	/* set dimensions of matrices Q and R based on full or thin QR */
	if(full) { // Q is m by m and R is m by n
		q_n = m;
		r_m = m;
	}	else { // Q is m by n and R is n by n
		q_n = n;
		r_m = n;
	}

	/* allocate memory for the matrices A and R */
	double ** a = new double*[q_n];
	double ** r = new double*[n];
	for (i = 0; i < n; i++) {
		a[i] = new double[m];
		r[i] = new double[r_m];
	}
	for(; i < q_n; i++) {
		a[i] = new double[m];
	}

	/* initialize the values in matrix A (only n columns regardless of
		 thin QR or full QR) */
	for(i = 0; i < n; i++) {
		for(j = i; j < m; j++) {
			a[i][j] = j - i + 1; // this choice of values was arbitrary
		}
	}

	print("A=", a, m, n);
	gramSchmidt(a, r, m, n, full);	// compute QR factorization
	print("Q=", a, m, n);

	print("R=", r, r_m, n);

	/* print numerical evidence that columns of Q are orthonormal */
	printf("Numerical verification that {q_1, ..., q_%i} is an "
				 "orthonormal set:\n", q_n);
	for(i = 0; i < q_n; i++) {
		for(j = i; j < q_n; j++) {
			double x = dot_product(a[i], a[j], m);
			printf("q_%i * q_%i = %lg\n", i + 1, j + 1, x);
		}
	}
    
	/* free memory */
	for(i = 0; i < n; i++) {
		delete[] a[i];
		delete[] r[i];
	}
	for(; i < q_n; i++) {
		delete[] a[i];
	}
	delete[] a;  
	delete[] r;
	return 0;
}
