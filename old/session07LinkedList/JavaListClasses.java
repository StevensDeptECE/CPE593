import java.util.*;

public class JavaListClasses {
    public static void main(String[] args) {
        final int n = 1000000;
        ArrayList<Integer> a = new ArrayList<>(n);
        for (int i = 0;  i < n; i++)
            a.add(i);
        for (Iterator<Integer> i = a.iterator(); i.hasNext(); ) {
            Integer x = i.next();
        }
        LinkedList<Integer> b = new LinkedList<>();
        for (int i = 0;  i < n; i++)
            a.add(i);
        for (Iterator<Integer> i = a.iterator(); i.hasNext(); ) {
            Integer x = i.next();
   
        }
    
    }
}
