
void makesubheap(int x[], int i, int n) {
  int left = 2*i+1;
	int right = 2*i+2;
	if (left >= n)
		return; // we are beyond the end of the array, get out									
	if (x[left] > x[right]) {
		if (x[left] > x[i]) {
			swap(x[left], x[i]);
			makesubheap(x, left, n);
		}
	} else {
		if (x[right] > x[i]) {
			swap(x[right], x[i])
				makesubheap(x, right, n);
		}
	}
}

void reformheap(int x[], int n) {
  makesubheap(x, 0, n);
}

void makeheap(int x[], int n) {
  for (int i = n/2; i > 0; i--)
		makesubheap(i, n);
}


void heapsort(int x[], int n) {
  makeheap(x, n);
	for (int i = n-1; i > 0; i--) {
		swap(x[0], x[i]);
	  reformheap(x, i);
	}
}
