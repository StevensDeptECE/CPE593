public class Permute {
    private int[] x;
    public Permute(int N) {
      x = new int[N];
      for (int i = 0; i < N; i++)
        x[i] = i;
      permute(N-1);
    }
    public void doit() {
        for (int i = 0; i < x.length; i++)
          System.out.print(x[i] + " ");
        System.out.println();
    }
    public void swap(int i, int j) {
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }
    public void permute(int n) {
      if (n == 0) {
        doit();
      }
      for (int c = 0; c <= n; c++) {
        swap(c, n);
        permute(n-1);
        swap(c, n);
      }
    }
    public static void main(String[] args) {
        Permute p = new Permute(4);
    }

}