#include <iostream>
using namespace std;

class MagicSquare {
private:
	int* s;
	int n;
	int rowSum;
	
	void print() const {
		int c = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++, c++)
				cout << s[c] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}

	void check() {
		int c = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++, c++)
				sum += s[c];
			if (sum != rowSum)
				return;
		}

		for (int i = 0; i < n; i++) {
			int c = i;
			int sum = 0;
			for (int j = 0; j < n; j++, c+=n)
				sum += s[c];
			if (sum != rowSum)
				return;
		}
		int d1 = 0, d2 = 0;
		for (int i = 0; i < n; i++) {
			d1 += s[i * n + i];
			d2 += s[i * n + n-1 - i];
		}
    if (d1 != rowSum || d2 != rowSum)
			return;
		print();
	}
	
	void generate(int N) {
		if (N == 0) {
			check();
			return;
		}
		for (int i = 0; i <= N; i++) {
			generate(N-1);
			swap(N % 2 != 0 ? s[0] : s[i], s[N]);
		}
			
	}
public:
	MagicSquare(int n) : n(n) {
		s = new int[n*n];
		for (int i = 0; i < n*n; i++)
			s[i] = i+1;
		rowSum = n * (n*n + 1) / 2; // the sum of each row, col, diagonal
		generate(n*n-1);
	}
};

int main() {
	MagicSquare m(4);
}
