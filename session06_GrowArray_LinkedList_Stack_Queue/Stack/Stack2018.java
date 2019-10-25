public class Stack2018 {
	private int[] stack;
	private int sp;
	public Stack2018(int n) {
		stack = new int[n];
		sp = 0;
	}

	public void push(int v) {
		stack[sp++] = v;
	}
	public int pop() {
		return stack[--sp];
	}
	public boolean isEmpty() {
		return sp == 0;
	}
}
