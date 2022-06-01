#include<iostream>
#include <string>
using namespace std;

/*
	3 4 5   1
        i
				j
		1  3  4  5
*/
template<typename T>
void insertionsort(T x[], int n) {
	for (int i = 1; i < n; i++) { //O(n)
		T temp = x[i];
		for (int j = i-1; j >= 0; j--) { //O(n/4) 0 + 1 + 2 + 3 + ... n-2
			if (x[j] > temp)
				x[j+1] = x[j];
		  else {
				x[j] = temp; // break out early, we found the spot!
				break;
			}
		}
		x[0] = temp; //TODO: this should only happen if break did NOT happen
	}
}

template<typename T>
void print(T x[], int n ) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << ' ';
	}
	cout << '\n';
}
		
int main() {
	int a[] = { 5, 4, 3, 2, 1};
	print(a, 5);
	insertionsort(a, 5);
	print(a,5);

	string b[] = { "test", "hello", "123", "MSFT"};
	insertionsort(b, 4);
	print(b,4);

}
