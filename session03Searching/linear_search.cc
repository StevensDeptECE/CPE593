//O(n) omega(1)    average(n/2)= O(n)
int linear_search(int x[], int n, int target) {
	for (int i = 0; i < n; i++)
		if (x[i] == target)
			return i;
	return -1;
}

//O(n)  omega(1)
linearSearch_sortedList(int x[], int n, int target) {
	for (int i = 0; i < n; i++)
		if (x[i] >= target)
			if (x[i] > target)
				return -1;
			return i;
	return -1;
}
