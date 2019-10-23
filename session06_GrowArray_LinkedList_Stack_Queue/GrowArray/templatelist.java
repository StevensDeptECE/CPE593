public class templatelist<T> {
	private T[] data;
	private int used;

	public templatelist(int initialSize) {
		data = new Object[initialSize];
		used = 0;
	}
}
