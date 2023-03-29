import java.util.*;

//https://stackoverflow.com/questions/46898/how-do-i-efficiently-iterate-over-each-entry-in-a-java-map
public class TestHashMap {
    public static void main(String[] args) {
        TreeMap<String,Double> m = new TreeMap();
        HashMap<String,Double> hm = new HashMap(1024);
        m.add("AAPL", 148.5);
        m.add("IBM", 123);
        m.add("MSFT", 243);
        for (Map.Entry<String, Double> entry : m.entrySet()) {
            System.out.println(entry.getKey() + "/" + entry.getValue());
        }

    }
}