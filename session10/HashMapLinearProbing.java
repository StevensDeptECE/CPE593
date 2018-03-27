public class HashMapLinearProbing<Key,Value> {
	private Key[] keys;
	private Value[] values;

	public HashMapLinearProbing(uint32_t initialSize) {
		keys = new Key[initialSize];
		values = new Value[initialSize];
	}

	public HashMapLinearProbing() {
		this(1024);
	}


	public static void main(String[] args) {
		HashMapLinearProbing<String, double> stockQuotes =
			new HashMapLinearProbing<>();

  	stockQuotes.put("AAPL", 170.5);
		stockQuotes.put("IBM", 142);
		stockQuotes.put("BIDU", 188.2);
		System.out.println(stockQuotes.get("AAPL"));
	}
}
