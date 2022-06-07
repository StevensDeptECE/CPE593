/******************************************************************************
 *  Dov Kruger hybrid of Hoare and Lomuto partitioning
 ******************************************************************************/
import java.util.*;

public class QuickDK {

    public static void partialQuicksort(int[] a) {
        partialQuicksort(a, 0, a.length - 1);
    }

    private static int k = 1;
    private static Random rnd = new Random();
    private static int pickRand(int L, int R) {
        return L + rnd.nextInt(R-L+1);
    }
    private static void partialQuicksort(int[] a, int L, int R) {
        int r = pickRand(L, R);
        int pivot = a[r];
        //        System.out.println("Selected pivot" + r + "=" + a[r]);
        a[r] = a[R]; // there is nothing in a[R] now
        int i = L, j = R-1;
        out:
        while (i < j) {
            while (a[i] < pivot) {
              i++;
              if (i >= j)
                break out;
            }
            while (a[j] >= pivot) { // values equal to the pivot 
                //have to go somewhere, in this case, right side
                j--;
                if (i >= j)
                  break out;
            }
            exch(a, i, j); // swap the values on the left and right sides (like Hoare)
        }
        // at the end, i==j
        if (a[i] >= pivot) { // if a[i] belongs in the right partition
            a[R] = a[i]; // move it to the empty slot
            a[i] = pivot; // put the pivot here
        } else { // otherwise the first member of the right partition is i+1
            a[R] = a[i+1]; // move it to the empty slot
            a[i+1] = pivot; // put the pivot between the two partitions
        }
        //showPartition(a, L, i, R);
        if (i - L > k)
          partialQuicksort(a, L, i-1); // left hand side
        if (R - i > k)
          partialQuicksort(a, i+1, R); // right hand side does not include pivot
    }
        
    // exchange a[i] and a[j]
    private static void exch(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    // print array to standard output
    private static void showPartition(int[] a, int L, int pivot, int R) {
        for (int i = L; i < pivot; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.print("[" + a[pivot] + "] ");
        for (int i = pivot+1; i <= R; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    // print array to standard output
    private static void show(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static void FischerYates(int [] a) {
        for (int i = a.length-1; i > 0; i--)
          exch(a, i, pickRand(0, i));
    }
    public static int checkMonotonic(int [] a) {
        int errCount = 0;
        for (int i = 0; i < a.length-1; i++)
          if (a[i] > a[i+1])
            errCount++;
        if (errCount > 0) {
          //System.out.print("Errors: " + errCount + ": ");
          //show(a);
        } else
         ; //show(a);
         return errCount;
    }
    // test with numbers 0... n-1 in many orders
    public static void validate(int n, int numTrials) {
        int [] a = new int[n];
        int errCount = 0; // number of trials with errors
        for (int trials = 0; trials < numTrials; trials++) {
            for (int i = 0; i < n; i++)
              a[i] = i;
            FischerYates(a);
            partialQuicksort(a);
            if (checkMonotonic(a) != 0)
              errCount++;
        }
        System.out.println("tested " + n + " unique elements " + numTrials + " times with " + errCount + " errors");
    }
    public static void test(int a[], boolean print) {
        long t0 = System.nanoTime();
        partialQuicksort(a);
        long t1 = System.nanoTime();
        System.out.println("Elapsed time: " + (t1-t0));
        if (print)
            show(a);
        System.out.println("---------");
    }

    public static int[] generate(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
          a[i] = i;
        return a;
    }

    public static void main(String[] args) {
        validate(10, 1000);
        validate(11, 1000);
        validate(12, 1000);
        test(new int[]{15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, true);
        test(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true);
        test(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, true);
        test(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, true);
        //        test(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true);
//        test(new int[]{1, 2, 2, 2, 2, 2, 2, 2, 2, 3}, true);
//        for (int i = 100; i <= 100000000; i *= 10)
//        test(generate(i), false);
    }
}