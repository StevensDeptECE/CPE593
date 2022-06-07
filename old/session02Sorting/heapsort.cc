#include <iostream>

using namespace std;

void makesubheap(int x[], int i, int n) {
	int left = 2*i+1, right = 2*i+2;
	if (left >= n)
		return;
	if (right >= n) {
		if (x[i] < x[left]) {
			swap(x[i], x[left]);
			makesubheap(x, left, n);
		}
		return;
	}
	// guaranteed to have 2 children
	if (x[left] > x[right]) {
		if (x[left] > x[i]) {
			swap(x[i], x[left]);
			makesubheap(x, left, n);
		}
		return;
	} else {
		if (x[right] > x[i]) {
			swap(x[i], x[right]);
			makesubheap(x, right, n);
		}
		return;
	}
}

void makeheap(int x[], int n) {
	for (int i = n/2; i >= 0; i--)
		makesubheap(x, i, n);
}

void fixheap(int x[], int i) {
	makesubheap(x, 0, i);
}


void print(int x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << '\n';
}

void heapsort(int x[], int n) {
	makeheap(x, n);
	print(x, n);
	for (int i = n-1; i > 0; i--) {
		swap(x[0], x[i]); // put the biggest element in the correct place
		fixheap(x, i);
	}
}

int main() {
	int x[] = {1,2,3,4,5,6,7,8};
	heapsort(x, sizeof(x)/sizeof(int));
	print(x, sizeof(x)/sizeof(int));
}
