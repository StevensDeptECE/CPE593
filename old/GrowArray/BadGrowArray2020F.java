public class BadGrowArray2020F {
    private int[] data;

    public BadGrowArray2020F() {
        data = new int[0];
    }

    public void addEnd(int v) {
        int[] old = data;
        data = new int[old.length+1]; //O(n)
        System.arraycopy(old, 0, data, 0, old.length);//O(n)
        data[old.length] = v;
        //remove old
    }

    public void addStart(int v) {

    }

    public void insert(int v, int i) {
        int[] old = data;
        data = new int[old.length+1];
        System.arraycopy(old, 0, data, 0, i);
        System.arraycopy(old, i+1, data, i+1, old.length - i);
        data[i] = v;
        // no delete! garbage collector takes care of it
        // BUT YOU MUST write pseudocode because it happens
        //remove(old)  garbage collector deletes mem.
    }
    public void removeEnd() { //O(n)
        int [] old = data;
        data =  new int[old.length-1];
        System.arraycopy(old, 0, data, 0, data.length);
        // remove(old) garbage collector..
    }
    public void removeStart() {//O(n)

    }
    public void remove(int i) {//O(n)

    }

    public int getSize() {
        return data.length;
    }

}