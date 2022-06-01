#include <iostream>
using namespace std;

class Permute {
private:
	int* data;
	int n;
	void swap(int& a, int& b) {
		int temp = a; a = b; b = temp;
	}
public:
	Permute(int* data, int n) : data(data), n(n) {
		generate(n-1);
	}
	void generate(int N) {
		if (N == 0) {
			doit();
			return;
		}
		if (N % 2 == 0) {
			for (int c = 0; c <= N; c++) {
				generate(N-1);
				swap(data[0], data[N]);
			}
		} else {
			for (int c = 0; c <= N; c++) {
				generate(N-1);
				swap(data[c], data[N]);
			}
		}
	}
	void doit() const {
		for (int i = 0; i < n; i++)
			cout << data[i] << ' ';
		cout << '\n';
	}

};

int main() {
	int x[] = {1, 2, 3, 4};
	Permute p(x, 3);
}
	
