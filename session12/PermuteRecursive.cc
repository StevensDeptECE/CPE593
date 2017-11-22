#include <iostream>
using namespace std;

class Permute {
private:
	int* p;
	int N;
public:
	Permute(int x[], int N) : p(x), N(N) {
		//		generate(N-1);
		heaps(N-1);
	}
	void generate(int n) {
		if (n == 0) {
			doit();
			return; // What Sedgewick forgot!!!!
		}
		for (int c = 0; c <= n; c++) {
			swap(p[c], p[n]);
			generate(n-1);
			swap(p[c], p[n]);
		}
	}
	void heaps(int n) {
		if (n == 0) {
			doit();
			return; // What Sedgewick forgot!!!!
		}
		for (int c = 0; c <= n; c++) {
			generate(n-1);
			swap(n % 2 ? p[0] : p[c] , p[n]);
		}
	}

	void doit() const {
		for (int i = 0; i < N; i++)
			cout << p[i];
		cout << '\n';
	}
};


int main() {
  int x[] = {1, 2, 3, 4};
	Permute perm(x, 4);

}
