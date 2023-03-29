import java.util.LinkedList;

public class HashMapLinearChaining {
  private static class Node {
    int key;
    int val;
  }
  private LinkedList[] table;
  int capacity;
  int size; // how many values are in the table

  private void grow() {

  }

  public HashMapLinearChaining(int capacity) {

  }
  public void add(int key, int val) {

  
  }

  public Integer get(int key) {
    return null; // TODO: implement this

  }

  // remove an key-value pair from the hash map
  public void remove(int key) {

  }

  public void histogram() {

  }
  
  public static void main(String[] args) {
    HashMapLinearChaining m = new HashMapLinearChaining(1024);
    for (int i = 0; i < 2000; i++)
      m.add(i, 2*i); // you have to grow!! probably when table is about 75% full
    m.add(0, 93);
    m.remove(5);

    for (int i = 1; i < 10; i++) {
      Integer p = m.get(i);
      if (p != null)
        System.out.println(p);
    }


  }
}