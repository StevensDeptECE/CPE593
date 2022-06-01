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

	void generate(int n) {
		if (n <= 0) {
			doit();
			return;
		}
		for (int c = 0; c <= n; c++) {
			/* you need to figure out how to skip a lot of it
			if (test(c) ) {
				// if this case does not work, skip a whole range
				return;
			}
			*/

			generate(n-1);
			swap(p[n % 2 == 0 ? 0 : c], p[n] );
		}
			
	}
};


int main() {
	Permutation p1(4);
}
