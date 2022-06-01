import java.util.HashMap;
import java.util.TreeMap;
import java.util.*;
public class JavaHashing {
	public static void main(String[] args) {
		HashMap<String, Double> map = new HashMap<>();
		map.put("IBM", new Double(118.0));
		map.put("X", 62.0);
		map.put("AAPL", 147.0); // new Double(147)
		map.put("JPM", 105.0);
		map.put("YYY", 5.0);
		map.put("QQQ", 92.5);
		System.out.println(map.get("AAPL"));

		for (Iterator it = map.entrySet().iterator(); it.hasNext(); ) {
        Map.Entry pair = (Map.Entry)it.next();
        System.out.println(pair.getKey() + " = " + pair.getValue());
				//        it.remove(); // avoids a ConcurrentModificationException
    }

		for (Map.Entry<String, Double> cursor : map.entrySet())
			System.out.println(cursor.getKey() + "==>" + cursor.getValue());
	}
}
			 
