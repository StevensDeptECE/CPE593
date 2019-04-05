import java.util.*;
public class JavaMap {
	public static void main(String[] args) {
		TreeMap<String, Double> t = new TreeMap<>();
		t.put("IBM", 152.25);
		t.put("BIDU", 138.5);
		t.put("AAPL", 119.0);
		for(Map.Entry<String,Double> entry : t.entrySet()) {
			String key = entry.getKey();
			Double value = entry.getValue();

			System.out.println(key + " => " + value);
		}
}


	}

	
