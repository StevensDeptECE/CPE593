public class JavaStringPerformance {
	public static void main(String[] args) {
		String s = "abc";
		s = s + "def";

		String s2 = "";
		for (int i = 0; i < 1000000; i++)
			s2 = s2 + i;

		Integer x = new Integer(5);

		String s3 = x.toString();

		Bond b = new Bond("IBM", 4.5, "2020-01-01");
		String s4 = b.toString();

		StringBuilder b = new StringBuilder();
		b.append("testing");
		b.append(5);
		b.append('x');
		return b.toString();
		
	}
}

class A {
	public String toString() {
		return comp1.toString() + "msg=" + comp2.toString();

}
