public class BadGrowArray2018F {
	private	int len;
	private int[] data;

	public BadGrowArray() {
		data = null; // new int[len]
		len = 0;
	}
	public void insertEnd(int v) {
		int[] old = data;
		data = new int[len+1];
		for (int i = 0; i < len; i++)
			data[i] = old[i];
		data[len] = v;
		len++;
	}
	
  public void insertStart(int v) {
		int[] old = data;
		data = new int[len+1];
		data[0] = v;
		for (int i = 0; i < len; i++)
			data[i+1] = old[i];
		len++;
	}

  public void insert(int i, int v) { //O(len)
		int[] old = data;
		data = new int[len+1];
		for (int j = 0; j < i; j++)
			data[j] = old[j];
		data[i] = v;
		for (int j = i; j < len; j++)
			data[j+1] = temp[j];
		len++;
	}

	
	// remove from end and return the value being removed
	public int removeEnd() {  //O(1)
		int temp = data[len-1];
		len--;
		return temp;
	}

	public int removeStart() { //O(len)
		int temp = data[0];
		--len;
		for (int i = 0; i < len; i++)
      data[i] = data[i+1];			
	}

  public int get(int pos)  {
		return data[pos];//O(1)
	}
	public int getSize() { //O(1)
		return len;
	}
	public String toString() {
		// StringBuilder b = new StringBuilder();
		// b.append( );
		// return b.toString();
		String s = "";
		for (int i = 0; i < length; i++)
			s += data[i] + ' ';
		return s;
	}
	
	public static void main(String[] args) {
		BadGrowArray b = new BadGrowArray();
    final int n = 10;
		for (int i = 0; i < n; i++)
			b.insertEnd(i); // 1 + 2 + 3 + ....  + n = O(n^2)
		for (int i = 0; i < n; i++)
			b.insertStart(i); // 1 + 2 + 3 + ....  + n = O(n^2)
		b.insert(5, 99);
		System.out.println(b);
	}

	
}

