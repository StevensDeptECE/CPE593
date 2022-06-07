public class Permute {
	private int[] list;
	
	private void exch(int i, int j) {
    int temp = list[i]; list[i] = list[j]; list[j] = temp;
	}

	public void doit() {
		for (int i = 0; i < list.length; i++)
			System.out.print(list[i] + " ");
		System.out.println();
	}
	
	void heaps(int N) {
		if (N == 0) {
			doit();
			return;
		}
		for (int c = 0; c <= N; c++) {
			exch(N % 2 != 0 ? 0 : c, N);
			heaps(N-1);
		}
	}
  void simple(int N) {
		if (N == 0) {
			doit();
			return;
		}
		for (int c = 0; c <= N; c++) {
			exch(c, N);
			simple(N-1);
			exch(c, N);
		}
	}

	public Permute(int[] list) {
		this.list = list;
		heaps(list.length-1);
	}
	
	public static void main(String[] args) {
		int[] x = {1, 2, 3, 4};
		new Permute(x);
	}
}
