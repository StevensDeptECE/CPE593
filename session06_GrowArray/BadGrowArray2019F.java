public class BadGrowArray2019F {
	private  int[] p;
	
	public BadGrowArray2019F() { p = new int[0]; }
	
	public int size() {
		return p.length;
	}

	public int get(int i) {
		return p[i];
	}
	public void addEnd(int v) { //O(n)
		int[] old = p; //O(1)
		p = new int[old.length+1]; //O(1)
		for (int i = 0; i < old.length; i++) //O(len)
			p[i] = old[i];
		p[old.length] = v; //O(1)
	}
	public void addStart(int v) { //O(n)
		int[] old = p;
		p = new int[old.length+1];
		for (int i = 0; i < old.length; i++) //O(n)
			p[i+1] = old[i];
		p[0] = v;
	}
	public void removeEnd() { //O(n)
		int[] old = p;
		final int len = old.length-1;
		p = new int[len];
		for (int i = 0; i < len; i++)
			p[i] = old[i];
	}
	public void removeStart() { //O(n)
		int[] old = p;
		final int len = p.length - 1;
		p = new int[len];
		for (int i = 0; i < len; i++)
			p[i] = old[i+1];
	}

	public static void main(String[] args) {
		BadGrowArray2019F a = new BadGrowArray2019F();
		a.addEnd(3); //O(1)
		a.addEnd(1); //O(2)
		a.addEnd(4); //O(3)
		a.addStart(1);
		final int n = 10;
		for (int i = 0; i < n; i++)
			a.addEnd(i); // 1 + 2 + 3 + ... + (n-2) + (n-1) = 
		for (int i = 0; i < a.size(); i++)
			System.out.print(a.get(i) + " ");
		System.out.println();
	}
}
