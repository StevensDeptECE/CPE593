class Backtrack2022 {
	private int N;
	private int a[];

	Backtrack2022(int N) {
		this.N = N;
		a = new int[N];
		for (int i = 0; i < N; i++)
			a[i] = i+1; // 1 2 3 4
		backtrack(N);
	}
	private void swap(int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	public void backtrack(int n) {
		if (n == 0) {
			//doit();
			return
		}
		for (int c = 0; c < n; c++) {
			//	constraint()		filter(); return if not good
			swap(c, n-1);
			backtrack(n-1);
			swap(c, n-1);
		}
	}

	public void heaps(int n) {
		if (n == 0) {
			//doit();
			return
		}
		for (int c = 0; c < n; c++) {
			backtrack(n-1);
			swap(c % 2 == 1 ? 0 : c, n-1);
		}		
	}
}
/*
    1  5  9
    2  

    What size problem could I reasonably solve in n queens on my laptop?
     a) 9
     b) 30
     c) 200
     d) all too computationally complex
 */
