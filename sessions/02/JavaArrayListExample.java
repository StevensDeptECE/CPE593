import java.util.*;

public class JavaArrayListExample {
    public static void main(String[] args)  {
      final int n = 1000000;
      ArrayList<int> a = new ArrayList<>(n);
      for (int i = 0; i < n; i++)
        a.add(i);
    }
}