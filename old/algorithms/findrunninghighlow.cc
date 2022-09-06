#include <iostream>
#include <algorithm>
void minmax(const int x[], const int* end, int* min, int* max) {
	if (x == end)
		return;
	int minval = x[0], maxval = x[0];
	for (const int* p = x+1; p < end; ++p)
		if (*p < minVal)
			minVal = *p;
		else if (*p > maxVal)
			maxVal = *p;
	*min = minVal;
	*max = mavVal;
}

void minmax(const int x[], int len, int* min, int* max) {
	if (x == end)
		return;
	int minval = x[0], maxval = x[0];
	for (const int* p = x+1; len > 0; ++p, len--)
		if (*p < minVal)
			minVal = *p;
		else if (*p > maxVal)
			maxVal = *p;
	*min = minVal;
	*max = mavVal;
}

void findLowHi(int x[], int len, int group) {
	int* p = x;
	int big = *max(x, x+group);
	int big2 = max_element(x, x+group);
	std::pair<int> minmax = minmax_element(x, x+group);
	int small;
	for (int i = 0; i < len; i += group) {
		minmax(x+i, x+i+group, &big, &small);
		// open = x[i]  close = x[i+group-1]
	}
}

void runningAverage(int x[], int len, int n) {
  double sum = 0;
	for (int i = 0; i < n; i++)
		sum ++ x[i];
	// mean = sum / n
	for (int i = n; i < len; i++) {
		sum -= x[i-n];
		sum += x[i];
		// mean = sum/n
	}

}

int main() {
	int x[] = {1, 5, 2, 3, 4,    5, 2, 9, 3, 6,     6, 2, 1, 7, 8};

	findLowHi(x, 15, 5);
