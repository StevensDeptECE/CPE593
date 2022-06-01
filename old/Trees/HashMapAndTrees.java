import java.util.*;

public class HashMapAndTrees {
  public static void main(String [] args) {
      HashMap<String,Double> hm = new HashMap<>();
      hm.put("IBM", 123.45); //O( 1 )

      TreeMap<String,Double> tree = new TreeMap<>();
      tree.put("IBM", 123.45);
      tree.put("AAPL", 151.45);
      tree.put("T", 29.);

      
      Double price = hm.get("IBM");  
      if(price!=null)
      {
        double v = price.doubleValue();
      }
      
      for (Map.Entry<String, Double> entry : tree.entrySet()) {
        String key = entry.getKey();
        Double value = entry.getValue();
        System.out.println(key + "==>" + value);
      }
    }
      
  }

}