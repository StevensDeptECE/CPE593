package magicsquarebruteforce2018s;

/**
 * @author dkruger
 */
public class MagicSquareBruteForce2018S {

    private int[] s;
    private int n;
    private int rowSum;

    public MagicSquareBruteForce2018S(int n) {
        this.n = n;
        s = new int[n * n];
        for (int i = 0; i < n * n; i++) {
            s[i] = i + 1;
        }
        // 1 2 3 4 5 6 7 8 9

        //N=n**2 - 1
        rowSum = n * (n * n + 1) / 2; // sum for each row, column, diagonal
        System.out.println("Row sum=" + rowSum);
        simple(s.length - 1);
    }

    private void swap(int i, int j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    //O(n*n)
    private void check() {
        // for (int i = 0; i < s.length; i++)
        //     System.out.print(s[i] + " ");
        // System.out.println();
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = j * n; i < j * n + n; i++) {
                sum += s[i];
            }
            if (sum != rowSum) {
                return;
            }
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = j; i < j + n * n; i += n) {
                sum += s[i];
            }
            if (sum != rowSum) {
                return;
            }
        }
        /*
			a  b  c
			d  e  f
			g  h  i
         */
        int d1 = 0;
        for (int i = 0; i < s.length; i += n + 1) {
            d1 += s[i];
        }
        if (d1 != rowSum) {
            return;
        }
        int d2 = 0;
        for (int i = n - 1; i < s.length; i += n - 1) {
            d2 += s[i];
        }
        if (d2 != rowSum) {
            return;
        }
        print();
    }

    private void simple(int N) {
        if (N == 0) {
            check();
            return;
        }

        for (int c = 0; c <= N; c++) {
            swap(c, N);
            simple(N - 1);
            swap(c, N);
        }
    }

    public void print() {
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++, c++) {
                System.out.print(s[c] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        new MagicSquareBruteForce2018S(3);
    }

}
