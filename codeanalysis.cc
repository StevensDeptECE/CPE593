// O() omega()
int func1(int n) {
	for (int i = n-1; i > 0; i--)
		if (i % 17 == 0)
			return i;
	return 0;
}

//O() omega()
int func2(int n) {
	int sum = 4;
	for (int i = n-1; i > 0; i--)
		for (int j = 0; j < i + 3; j++)
			sum += 3;
	return sum;
}

// Q: can you write func2 more efficiently?

int func3(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;
	return sum;
}

//Q: can you write func3b more efficiently?
//Q2: is this more efficient than func3?
int func3b(int n) {
	int sum = 1;
	for (int i = 2; i <= n; i++)
		sum += i;
	return sum;
}

// see: https://en.wikipedia.org/wiki/Perfect_number
// should return true if the number is perfect, false otherwise.
// this code is wrong. It is also horribly inefficient.
// can you make it better?
// it should return true if the parameter is perfect.
bool perfect(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			sum += i;
	return sum == n;
}

double fact(int n) {
	double p = 1;
	for (int i = 1; i <= n; i++)
		p *= i;
	return p;
}

// Q: What is the complexity?
// Q2: can you make one faster, perhaps using memoization?
double choose(int n, int r) {
	return fact(n) / (fact(r) * fact(n-r));
}


// Do this test more efficiently
bool countPrimesProb(uint64_t a, uint64_t b) {
	uint32_t count = 0;
	for (uint64_t i = a; i <= b; i++)
		if (isPrime(i))
			count++;
	return  (b - a + 1) / count <= 2;
}
