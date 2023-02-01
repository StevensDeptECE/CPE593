public class BadDynamicArray {
  private int[] data;
  public BadDynamicArray() { data = null; }

  public int len() { //O(1)
    if (data != null)
      return data.length;
    else
      return 0;
  }

  public int get(int i) { //O(1)
    return data[i];
  }
  public void addEnd(int v) {
    int capacity = data != null ? data.length : 0;
    int[] temp = new int[capacity+1]; //O(capacity)
    for (int i = 0; i < capacity; i++) //O(capacity)
      temp[i] = data[i]; 
    temp[capacity] = v;//O(1)
    data = temp; //O(1)
  }
  public void addFirst(int v) {
    int capacity = data != null ? data.length : 0;
    int[] temp = new int[capacity+1];
    temp[0] = v; // copy in new element O(1)
    for (int i = 1; i <= capacity; i++) {
        temp[i] = data[i-1];
    }
    data = temp; //O(1)
  }

  // insert before position pos
  public void insert(int pos, int v) {}
  public void removeEnd() {//O(capacity)
    int capacity = data != null ? data.length : 0;
    int[] temp = new int[capacity-1];
    for (int i = 0; i < capacity-1; i++) {
        temp[i] = data[i];
    }
    data = temp; //O(1)
  }
  public void removeFirst() {//O(capacity)
    int capacity = data != null ? data.length : 0;
    int[] temp = new int[capacity-1];
    for (int i = 1; i < capacity; i++) {
        temp[i-1] = data[i];
    }
    data = temp; //O(1)
  }
  public void remove(int pos) {}            //TODO: implement!
  public void replace(int search, int repl) {} //TODO: implement!
  public int get(int pos) {
    return data[pos];
  }
  public void set(int pos, int val) {
    data[pos] = val;
  }
  public String toString() {
    String s = ""; //O(1)
    if (data == null) //O(1)
      return s;
    for (int i = 0; i < data.length; i++)//O(length)
      s = s + data[i] + " "; // "" + 1 --> "1" + 2 --> "12"
    return s;
  }

 public static void main(String[]args) {
   BadDynamicArray a1 = new BadDynamicArray(); //O(1)
   System.out.println(a1.len()); // O(1)
   a1.addEnd(3); //O(1)
   final int n = 10;
   for (int i = 1; i <= n; i++)
    a1.addEnd(i); // 1 + 2 + 3 + ... + n = O(n^2)
   a1.addFirst(9);
   a1.insert(5, -3);
   System.out.println(a1);
   a1.removeEnd();
   a1.removeFirst();
   a1.remove(3);
   System.out.println(a1);

   int v = a1.get(3);
   System.out.println(a1.get(3));
   System.out.println(a1.get(15));
  }
}