import java.util.*;

public class SlowJavaList {
    public static void main(String[] args) {
        long t0 = System.nanoTime();
        final int n = 100000000;
        ArrayList<Integer> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(i);
        }

        for (int i = 0; i < n; i++)
            a.set(i, a.get(i) + 1);
        long t1 = System.nanoTime();
        System.out.println((t1-t0)*1e-9);
    }
}
