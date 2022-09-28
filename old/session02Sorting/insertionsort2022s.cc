#include <iostream>
using namespace std;

// 1 5 2
// 1 2 5 x
// this one goes right to left
void insertion(int a[], int n) {
	for (int i = 1; i < n; i++) { // start with element 1,
		//0 is already sorted
		if (a[i] < a[i-1]  ) {
			int temp = a[i];
			int j;
			for (j = i-1;  j >= 0; j--) {
				if (temp > a[j]) {
					a[j+1] = temp;
					break;
				}
        a[j+1] = a[j]; // copy from the left
			}
			if (j == -1) {
				a[0] = temp;
      }
		}
	}
}

int main() {

}

