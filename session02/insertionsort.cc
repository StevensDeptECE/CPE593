void insertionsort(int x[], int n) { //O(n^2) omega(n)
	for (int i = 1; i < n; i++) { // n-1 O(n)
		int temp = x[i];
		for (int j = i-1; i >= 0; i--) // 1 + 2  + 3 + ... n-1
			if (x[i] > x[j]) {
				x[j+1] = x[j];
			} else {
				x[j+1] = temp; // insert the value  //omega(1)
				break;
			}
	}
}
