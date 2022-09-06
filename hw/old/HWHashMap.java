/*
	Implement methods add(), get() and hist() for both types of hashmap

	You must read the file dict.txt in the current directory.
	DO NOT put in a path, that will only work on your computer.

	https://drive.google.com/drive/folders/0Bwxfq4Y7f7vkTkZnVEFEcXVEWmc?resourcekey=0-mOXByawNd1BgAZIqFmdGzQ&usp=sharing
 */
public class HWHashMap {
	public static void main(String[] args) {
	constexpr int n = 1000000;
	HashMapLinearProbing m1 = new HashMapLinearProbing(n);
	HashMapLinearChaining m2 = new HashMapLinearChaining(n);

	int count = 0;
	//read in the dictionary (213k words)
	{// write your loop!
		m1.add(word, count); // each word has a unique id number
		m2.add(word, count);
		count++;
	}

	System.out.println("Linear probing\n");
	final String words[] = {"apple", "bear", "cat", "dog", "arggg",
												"juwqehtrkqwejhr"};
	for (int i = 0; i < words.length; i++) {
		Integer id = m1.get(words[i]); // return null if not found
		System.out.println("word " +  words[i] + " " + id + "id=" + id + '\n');
	}
	// print out the histogram showing count of inserts taking 1, 2, 3, ... 9+
	m1.hist();
	
	System.out.println("\n\nLinear chaining\n");
	for (int i = 0; i < words.length; i++) {
		Integer id = m2.get(words[i]); // return null if not found
		System.out.println("word " +  words[i] + " " + id + "id=" + id + '\n');
	}
	// print out the histogram showing bins of size 0, 1, 2, 3, ... 9+
	m2.hist();
}
