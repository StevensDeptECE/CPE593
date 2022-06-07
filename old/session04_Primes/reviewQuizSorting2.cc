void quicksort(int x[], int L, int R) {
	int i = L, j = R;
	int pivot = x[random(L, R)]
	while (i <= j) {
    while (x[i] < pivot && i < j)
			i++;
		while (x[j] >= pivot && i < j)
			j--;
		if (i < j)
			swap(x[i], x[j])
	}
	if (i-L > 1 )
		quicksort(x, L, i);
	if (R - (i+1) > 1)
		quicksort(x, i+1, R);
}

quicksort(x) {
	quicksort(x, 0, x.length-1)
}

bisection(x, target) {
	bisection(x, L, R, target)
}

bisection(x, L, R, target) {
	if (L > R)
		return -1;
	int mid = (L+R)/2;
	if (x[mid] > target)
		return bisection(x, L, mid-1, target);
	else if (x[mid] < target)
		return bisection(x, mid+1, R, target);
	return mid;
}







