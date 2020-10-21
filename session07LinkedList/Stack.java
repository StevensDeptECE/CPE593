import java.util.ArrayList;

public class Stack {
    private ArrayList<Integer> impl;

    public Stack() {
        impl = new ArrayList<>();
    }
    public void push(int v) {
        impl.add(v); //O(1)
    }
    public void pop() { //O(1)
        impl.removeEnd();
    }
    public int last() {
        return impl.get(impl.size()-1);
    }
    public boolean isEmpty() { //O(1)
        return impl.size() == 0;
    }    
}
