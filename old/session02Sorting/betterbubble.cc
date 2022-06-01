#include <iostream>
using namespace std;

void bubbleSort(int x[], int n) {
	for (int i = 0; i < n-1; i++) {
		bool sorted = true;
		for (int j = 0; j < n-1-i; j++)
			if (x[j] > x[j+1]) {
				swap(x[j], x[j+1]);
				sorted = false;
			}
		if (sorted)
			return;
	}
}
				
