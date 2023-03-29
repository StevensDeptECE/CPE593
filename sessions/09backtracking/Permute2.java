public class Permute2 {
    private int[] x;
    public Permute2(int N) {
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
      permute(n-1);
      for (int c = 0; c <= n; c++) {
        if (c % 2 != 0)
          swap(0,n);
        else
          swap(c, n);
      }
    }
    public static void main(String[] args) {
        Permute2 p = new Permute2(4);
    }

}