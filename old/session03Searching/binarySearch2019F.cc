#include <iostream>
using namespace std;
// -1 means number not found
int binarySearch(int list[], int n, int target) {
	int L = 0, R = n-1;
	if (target < list[L] || target > list[R])
		return -1;
	while (L <= R) {
		int G = (L + R) / 2;
		if (list[G] < target) {
			L = G + 1; // VERY important, must be +1
		} else if (list[G] > target) {
			R = G - 1;
		} else {
			return G;
		}
	}
	return -1;
}

// -1 means number not found
int recursivebinarySearch(int list[], int L, int R, int target) {
  if (L > R)
		return -1;
	int G = (L+R)/2;
	if (list[G] > target)
		return recursivebinarySearch(list, G+1, R, target);
	if (list[G] < target)
		return recursivebinarySearch(list, L, G-1, target);
  return G;
}




//  O(log n)
// omega(1) binary search looking for an element > any in the list

/*
	list of n = 10^9 elements
  searching m =1000 times

	choice 1. sort, then search using binary search   O(n log n) + O(m * log n) = 10^9 * 30+1000*30
	choise 2. don't sort, just use linear search      O(n*m) = 10^12

is it worth using binary search???



  list of n = 10^5
  m = 50

	how to search?
 */


int main() {
	int x[] = {1, 2, 3, 9, 11, 16, 25, 31, 46, 92};
	const int n = sizeof(x)/sizeof(int);
	cout << binarySearch(x, n, 10) << '\n';
	cout << binarySearch(x, n, 11) << '\n';
	cout << binarySearch(x, n, 92) << '\n';
	cout << binarySearch(x, n, 1) << '\n';
	cout << binarySearch(x, n, 0) << '\n';
	cout << binarySearch(x, n, 100) << '\n';
}
