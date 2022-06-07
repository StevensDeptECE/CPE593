import java.util*;

/*
class MyNumberHashMap {
	private static class Node {
		String key;
		double v;
	}
*/
public class UsingJavaHashmaps {
	public static void main(String[] args) {
		
		TreeMap<String, Double> quote = new Treemap<>();
		quote.put("XOM", 72);
		quote.put("AAPL",181);
		quote.put("IBM", 144);

		Double d = quote.get("XOM");
		System.out.println(d);
		if (d == null) {

		}

		//		https://stackoverflow.com/questions/1066589/iterate-through-a-hashmap
		
}
