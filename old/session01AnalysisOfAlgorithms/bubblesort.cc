void bubblesort(int x[], int n) { //O(n^2)
	for (int j = n-1; j > 0; j--) // O(n)
		for (int i = 0; i < j; i++) { //n-1 + n-2 + n-3 + ... + 1   
			if (x[i] > x[i+1]) {
				int temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
	}

}

int main() {
	int x[] = {1, 2, 3, 4, 5};
	int y[] = {4, 3, 2, 1, 5};
	int z[] = {5, 1, 2, 4, 3};

	
