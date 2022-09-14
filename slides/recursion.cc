int f(int n) {
	//	int x[2000000];
	int x[20];
	return f(n-1);
}

int fact(int n) {
	if (n < 0)
		return 1;
	return n * fact(n-1);
}

int main() {
	f(3);
}
