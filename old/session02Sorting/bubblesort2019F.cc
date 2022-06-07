//O(n**2)
void bubblesort(int x[], int n) {
  for (int j = n-1; j > 0; j--) // O(n)
		for (int i = 0; i < j; i++)   //O(n)
		if (x[i] > x[i+1]) {
			int temp = x[i];
			x[i] = x[i+1];
			x[i+1] = temp;
			/*
			x[i] = x[i] + x[i+1];
			x[i+1] = x[i] - x[i+1]; // old x[i]
			x[i] = x[i] - x[i+1];

			x[i] = x[i] ^ x[i+1];
			x[i+1] = x[i] ^ x[i+1];
			x[i] = x[i] ^ x[i+1];
			*/
		}
}
