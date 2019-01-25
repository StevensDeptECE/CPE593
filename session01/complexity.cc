void f() { //O(1)
}

int main() {
	for (int i = 0; i < n; i++) { //O(n)
		f(); //O(1)
	}

	for (int i = 5; i < n-60; i++) { //O(n)

	}

	for (int i = 5; i < n-60; i += 19) { //O(n)

	}

	for (int i = 0; i < n; i += n/3) { //O(1)

	}

	for (int i = n/2; i < n; i += 20) {// O(n)

	}

	//n=100  sqrt(n) = 10
	//n = 10000  sqrt(n) = 100
	for (int i = 0; i < sqrt(n); i++) { //O( sqrt(n)  )

	}

	for (int i = 0; i < n; i += sqrt(n)) { //O(sqrt(n)  )

	}

	for (int i = 0; i < n - sqrt(n); i++) { //O( n )


	}

	// 2^10 = 1024
	// 2^20 = 1024*1024
	// 2^30 = 1024^3
	for (int i = 1; i < n; i = i * 2) { // O(log2(n))

	}

	for (int i = 5; i <= n; i = i * 3) { // O(log3(n))

	}

	// all logs are the same for complexity	log2(n) = log3(n) / log2(3)

	//O(n^2)
  for (int i = 0; i < n; i++) { //O(n)
		for (int j = 0; j < n; j++) { //O(n)

		}
	}


	//O(sqrt(n)*log2(n)     )
	for (int i = 0; i < sqrt(n); i++) {
		for (int j = 1; j < n; j *= 2) {

		}
	}

	//O(n)
	for (int i = 0; i < n; i++)//O(n)
		;
	for (int i = 0; i < 2*n; i++) //O(2n) = O(n)
		;

	//O(n^2)
	for (int i = 0; i < n; i++) {//O(n^2)
		for (int j = 0; j < n; j++)
			;
	}
	for (int i = 0; i < 2*n; i++) //O(2n) = O(n)
		;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) { // 0 + 1 + 2 + 3 + ... + n-1
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) { // 1 + 2 + 3 + ... + n -1 + n
		}
	}

}

int fact(int n) { //O(n) omega(n)  (theta(n))
	int prod = 1;
	for (int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

int fact2(int n) {
	if (n == 0) //O(1)
		return 1;

	return n*fact2(n-1);
}

class Image {
private:
	int* data;
	int w, h;
public:
	void floodFill(int x, int y, int color) {	
		set(x,y, color);
		if (get(x+1,y) != color)
			floodFill(x+1,y,color);
		if (get(x-1,y) != color)
			floodFill(x-1,y,color);
		if (get(x,y+1) != color)
			floodFill(x,y+1,color);
		if (get(x,y-1) != color)
			floodFill(x,y-1,color);
	}
}

	






	
	
