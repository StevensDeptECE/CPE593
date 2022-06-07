#include <iostream>

using namespace std;

void perm(int x[], int N, int n) {
	if (n == 0) {
		for (int i = 0; i < N; i++)
			cout << x[i] << ' ';
		cout << '\n';
		return;
	}

	for (int c = 0; c <= n; c++) {
		swap(x[c], x[n]);
		perm(x, N, n-1);
		swap(x[c], x[n]);
	}
}

void heap(int x[], int N, int n) {
	if (n == 0) {
		for (int i = 0; i < N; i++)
			cout << x[i] << ' ';
		cout << '\n';
		return;
	}
	for (int c = 0; c <= n; c++) {
		heap(x, N, n-1);
		int which =  c % 2 == 1 ? 0 : c;
		cout << "swap(" << which << ", " << n << ")\n";
		swap(x[which], x[n]);
	}
}



int main() {
	const int N = 4;
	int x[N];
	for (int i = 0; i < N; i++)
		x[i] = i; // 0 1 2 3 4 ... n
	//	perm(x, N, N-1);
	heap(x, N, N-1);

}
