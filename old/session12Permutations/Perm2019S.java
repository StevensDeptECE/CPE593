public class Perm2019S {
	private int p[];
	private void swap(int i, int j) {
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
	public Perm2019S(int N) {
		p = new int[N];
		for (int i = 0; i < N; i++)
			p[i] = i;
		print();
		perm(N-1);
	}

	public void print() {
		for (int i = 0; i < p.length; i++)
			System.out.print(p[i] + " ");
		System.out.println();
	}

	public void perm(int n) {
    if (n == 0) {
			print();
			return;
		}
		for (int c = 0; c <= n; c++) {
			swap(c, n);
			perm(n-1);
			swap(c, n);
		}	
	}


	//Heap's
	public void perm2(int N) {
		if (N == 0) {
			print();
			return;
		}
		for (int c = 0; c <= N; c++) {
			perm2(N-1);
			swap(N % 2 == 1 ? 0 : c, N);
		}	
	}

	public static void main(String[] args) {
		Perm2019S p = new Perm2019S(4);

	}
}
