public class BadGrowArray2018S {
    private int[] data;
    public BadGrowArray2018S() {
	data = new int[0];
    }
    public void addEnd(int v) { //O(n)
	int[] old = data;
	data = new int[old.length+1]; //O(n)
	for (int i = 0; i < old.length; i++) //O(n)
	    data[i] = old[i];
	data[old.length] = v;
    }
    public void addStart(int v) { //O(n)
	int[] old = data;
	data = new int[old.length+1];
	for (int i = 0; i < old.length; i++)
	    data[i+1] = old[i];
	data[0] = v;
    }
    public void insert(int i, int v) { //O(n)
	int[] old = data;
	data = new int[old.length+1];
	for (int j = 0; j < i; j++)
	    data[j] = old[j];
	data[i] = v;
	for (int j = i+1; j < old.length; j++)
	    data[j+1] = old[j];
    }
    public void removeEnd() { // O(n)
	int[] old = data;
	data = new int[old.length-1];
	for (int i = 0; i < data.length; i++)
	    data[i] = old[i];
    }
    public void removeStart() {
    }
    public int size() {
	return data.length;
    }
    public boolean isEmpty() {
	return data.length == 0;
    }

}
