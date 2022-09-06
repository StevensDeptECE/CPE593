import java.io.*;

public class hwhash1 {
	public static void main(String[] args) throw Exception {
		FileReader fr = new FileReader("dict.dat");
		Scanner s = new Scanner(fr);
		String word;
		HashMapLinearChaining dict1 =
			new HashMapLinearChaining(50000); // initial size
    while (s.hasNext()) {
			word = s.next();
      dict1.add(word); // add the word to the dictionary
		}
		dict1.hist(); // display histogram
		s.close();
		//		fr.close();
		
		Scanner spell = new Scanner(new FileReader("words.dat"));
		
		while (spell.hasNext()) {
			word = spell.next();
			if (dict1.contains(word))
				System.out.println(word + " found!");
			else
				System.out.println(word + " not found!");
		}
	}
}
  
