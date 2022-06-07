import java.util.TreeMap; // RB-tree?
import java.util.HashMap; // hashing
public class Hashing2020F {
public static void main(String args[]) {

    // see: https://www.baeldung.com/java-iterate-map
    TreeMap<String,Double> quote = new TreeMap<>(1000);

    quote.put("MSFT", 208.22);
    quote.put("AAPL",159.62);
    quote.put("IBM", 175.22);

    Iterator<Map.Entry<String, Double>> iterator = quote.entrySet().iterator();
    while (iterator.hasNext()) {
        Map.Entry<String, Double> entry = iterator.next();
        System.out.println(entry.getKey() + ":" + entry.getValue());
    }

    if (quote.get("IBM") != null) {
        System.out.println(quote.get("IBM")); // print the value
    }

    HashMap<String,Double> quote2 = new HashMap<>(1000000);
    quote2.put("MSFT", 208.22);
    quote2.put("AAPL",159.62);
    quote2.put("IBM", 175.22);

    System.out.println(quote2.get("IBM"));
    Iterator<Map.Entry<String, Double>> i2 = quote2.entrySet().iterator();
    while (i2.hasNext()) {
        Map.Entry<String, Double> entry = i2.next();
        System.out.println(entry.getKey() + ":" + entry.getValue());
    }


}

}