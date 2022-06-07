/******************************************************************************
 *  Uses version of quicksort from K+R.
 *  Reference: The C Programming Language by Brian W. Kernighan and
 *  Dennis M. Ritchie, p. 87.
 *  Warning: goes quadratic if many duplicate keys.
 ******************************************************************************/

public class QuickKR {

    public static void sort(int[] a) {
        sort(a, 0, a.length - 1);
    }

    private static void sort(int[] a, int lo, int hi) { 
        if (hi <= lo) return;
        exch(a, lo, (lo + hi) / 2);  // use middle element as partition
        int last = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (a[i] < a[lo])
                exch(a, ++last, i);
            show(a);
        }
        exch(a, lo, last);
        sort(a, lo, last-1);
        sort(a, last+1, hi);
    }
        
    // exchange a[i] and a[j]
    private static void exch(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }


    // print array to standard output
    private static void show(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static void test(int a[], boolean print) {
        long t0 = System.nanoTime();
        QuickKR.sort(a);
        long t1 = System.nanoTime();
        System.out.println("Elapsed time: " + (t1-t0));
        if (print)
            show(a);
    }

    public static int[] generate(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
          a[i] = i;
        return a;
    }

    public static void main(String[] args) {
        test(new int[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, true);
        test(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true);
        test(new int[]{1, 2, 2, 2, 2, 2, 2, 2, 2, 3}, true);
        for (int i = 100; i <= 100000000; i *= 10)
        test(generate(i), false);
    }
}