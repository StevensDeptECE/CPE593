#include <vector>
#include <iostream>
using namespace std;

class Permutation {
private:
	vector<int> p; // Java: int[] p;
public:
	Permutation(int N) {
		for (int i = 0; i < N; i++)
			p.push_back(i);
		generate(N-1); // start permutations going...
	}

	void doit() {
		for (auto x : p) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	// if two queens are in the same diagonal, reject them
	inline bool sameDiagonal(int n, int pn, int i, int pi) {
		return i-n == abs(pn-pi);
	}
	bool filter(int c, int n) {
		for (int i = n+1; i < p.size(); i++)
			if (sameDiagonal(n, p[n], i, p[i]))
				return true;
		return false;
	}
	
	void generate(int n) {
		if (n <= 0) {
			doit();
			return;
		}
		for (int c = 0; c <= n; c++) {
			if (filter(c, n) ) {
				return;
			}

			generate(n-1);
			swap(p[n % 2 == 0 ? 0 : c], p[n] );
		}
			
	}
};

int main() {
	const int n = 4;
	Permutation queens(n);
	return 0;
}
