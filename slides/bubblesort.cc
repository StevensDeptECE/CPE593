void sort(int x[], int n) { // O(n^2)
	for (int i = n-1; i > 0; i--) { // O(n)
		for (int j = 0; j < i; j++) { // avg n/2
			if (a[j] > a[j+1]) { // O(1)
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
				 

}
