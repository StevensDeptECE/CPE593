#include <iostream>
using namespace std;

int binarySearch(int x[], int n, int target) {
  int L = 0, R = n-1;
	if (target < x[L] || target > x[R])
		return -1;
	
	while (L <= R) {
		int mid = (L+R)/2;
		if (x[mid] > target) {
			R = mid - 1;
		} else if (x[mid] < target) {
			L = mid + 1;
		} else
			return mid;
	}
	return -1;
}

int binarySearchRec(int x[], int L, int R, int target) {
	if (L > R )
		-1;
	int mid = (L+R)/2;
	if (x[mid] > target)
		return binarySearchRec(x, L, mid-1, target);
	else if (x[mid] < target)
		return binarySearchRec(x, mid+1, R , target);
	else
		return mid;
}

int x[] = {1, 3, 4, 5, 6, 9, 10, 19, 20, 26, 31, 40, 99, 200, 221};

int main() {
	int target = 6;
	//	cin >> target;
	
	cout << binarySearch(x, sizeof(x) / sizeof(int), target) << '\n';
}
