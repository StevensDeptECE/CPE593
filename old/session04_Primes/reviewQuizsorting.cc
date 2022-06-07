void quicksort(int x[], int L, int R) {
	int i = L, j = R;
	pivot = x[random(L, R)];
	while (i < j) {
 		while (x[i] < pivot && i < j)
			i++;
    while (x[j] > pivot && i < j)
			j--;
		if (i < j)
			swap(x[i], x[j])
	}

	if (L < j-1)
		quicksort(x, L, j-1);
	if (R > j+1)
		quicksort(x, j+1, R);

}

binarySearch(x, target) {
	return binarySearch(x, 0, x.length-1, target);
}
int binarySearch(x, L, R, target) {
	if (L > R)
		return -1;
	int mid = (L + R) / 2
		if (x[mid] < target)
			return binarySearch(x, mid+1, R, target);
	  else if (x[mid] > target)
			return binarySearch(x, L, mid-1, target);
	return mid;
}
				






