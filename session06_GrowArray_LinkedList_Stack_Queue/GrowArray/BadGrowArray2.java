public class BadGrowArray2 implements Cloneable {
	private	int[] data; // data.length
	public BadGrowArray2() {
		data = new int[0];
	}
	public Object clone() {
		BadGrowArray2 copy = new BadGrowArray2();
    copy.data = new int[this.data.length];
		for (int i = 0; i < data.length; i++)
			copy.data[i] = this.data[i];
	}
	
	public void addEnd(int v) { //O(n)
		int[] temp = data;
		data = new int[data.length+1];
    for (int i = 0; i < temp.length; i++)
			data[i] = temp[i];
		data[temp.length] = v;
	}

	void addStart(int v) { //O(n)
		int[] temp = data;
		data = new int[capacity+1];
		data[0] = v;
    for (int i = 0; i < temp.length; i++)
			data[i+1] = temp[i];
	}

	void insert(int i, int v) { //O(n)
		int* temp = data;
		data = new int[capacity+1];
    for (int j = 0; j < i; j++)
			data[j] = temp[j];
		data[i] = v;
		for (int j = i; j < capacity; j++)
			data[j+1] = temp[j];
		delete [] temp;
    capacity++;
	}
  void removeEnd() {
		int[] temp = data;
		data = new int[temp.length -1];
		/...
	}
	void removeStart() {
		int* temp = data;
		capacity--;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = temp[i];
		delete [] temp;
	}


  friend ostream& operator <<(ostream& s,const  BadGrowArray& a) {
		for (int i = 0; i < a.capacity; i++)
			s << a.data[i] << ' ';
		return s;
	}
	
};
void f(BadGrowArray a) {

}
public static void  main(String[] args) {
  BadGrowArray2  L1 = new BadGrowArray2();
  L1.addEnd(5);
  L1.addStart(3);
	BadGrowArray L2 = L1; // make a copy
	BadGrowArray L3;
	L2 = L3;
	f(L1);
  const int n = 10;
  for (int i = 0; i < n; i++) // 1+2+3 + ... + n
    L1.addEnd(i);
  L1.insert(2, 19); // insert the 19 before the 0
  L1.removeEnd(); // 9
  L1.removeStart(); // 3
  cout << L1 << "\n";
}
