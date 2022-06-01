double fact(int n) {
	if (n <= 1)
		return 1;
	return n*fact(n-1);
}

int count(int n) {
	if (n <= 0)
		return 0;
	return 1+count(n-1);
}

int main() {
	cout << fact(5); // 120
	int x;
	cin >> x;
	cout << fact(x);
	int prod = 1;
	for (int i = n; i > 1; i--)
		prod *= i;
}
