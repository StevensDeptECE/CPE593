#include <iostream>
#include <string>
using namespace std;
template<typename T>
void insertionsort(T x[], int n) {
	for (int j = 1; j < n; j++) {
		T temp = x[j]; // remember the new one
		for (int i = j-1; i >= 0; i--)
			if (x[i] > temp)
				x[i+1] = x[i];
			else {
				x[i+1] = temp;
				goto next; // get out of the inner loop
			}
		x[0] = temp;
	next:;
	}
		
}

template<typename T>
void print(const T x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	cout << '\n';
}

int main() {
	int a[] = { 5, 4, 3, 2, 1};
	print(a, 5);
	insertionsort(a, 5);
	print(a, 5);

	string b[] = {"test", "hello", "apple", "bear"};
	insertionsort(b, 4);
	print(b, 4);
							 
	return 0;
}
