public class JavaLists {
  public static void main(String[] args) {
    LinkedList<Integer> a = new LinkedList<>();
    for (int i = 0; i < 10; i++)
      a.add(i);
    for (Iterator<Integer> i = a.iterator(); i.hasNext(); ) {
      Integer v = i.next();
      System.out.print(v);
    }
  }
}
    
