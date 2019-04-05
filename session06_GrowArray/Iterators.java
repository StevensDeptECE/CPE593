public class Iterators {
	public static void main(String[] args) {
		ArrayList<Integer> a = new ArrayList<>();
		final int n = 10;
		for (int i = 0; i < n; i++)
			a.add(i);

		for (ListIterator<Integer> i = a.listIterator(); i.hasNext(); ) {
			Integer v = i.next();
		}
		

	}
}
