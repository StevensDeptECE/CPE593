#include <iostream>
using namespace std;

// this one goes right to left
void bubblesort(int a[], int n) {  // O(n^2)
	for (int j = 0; j < n-1; j++) { // O(n)
		for (int i = n-2-j; i >= 0; i--) { // (n-2 + 1) / 2 = n/2 O(n)
			if (a[i] > a[i+1] ) {
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}

}

void bubblesort2(int a[], int n) {
  for (int i = 0; i < n-2; i++) {
		if (a[i] > a[i+1] ) {
      //a[i] += a[i+1]; // a[i]  = sum of both
			//a[i+1] = a[i] - a[i+1];
			//a[i] -= a[i+1];
			a[i] ^= a[i+1];
			a[i+1] ^= a[i];
			a[i] ^= a[i+1];
		}
	}

}


int main() {
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	bubblesort(a, 10);

	int b[] = {5, 3, 1};
	bubblesort(b, 3);
}
