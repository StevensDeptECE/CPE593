public class StringsInJava {
	f(StringBuilder b) {
		b.append(...);
	}
	String f(String a, String b  ) {
		return a + b;
	public static void main(String[] args) {
		String s = "abc" + "def"; // "abcdef"
		String s1 = "";
		final int n = 1000000;
		for (int i = 0; i < n; i++)
			s1 += i; // s1 = "01234567891011121314...99"

		StringBuilder b = new StringBuilder();
		for (int i = 0; i < n; i++)
			b.append(i); // b = "01234567891011121314...99"
		String s1 = b.toString();
	}

}
