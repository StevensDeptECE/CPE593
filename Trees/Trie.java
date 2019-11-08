public class Trie {
	private static class Node {
		Node next[];
		boolean isWord;
		Node() {
			next = new Node[26];
		}
	}
	private	Node root;
	public Trie() { root = new Node(); }
	// load the trie from a dictionary file
	public void load(String dictionary) {

	}

	public void add(String word) {

	}

	public void remove(const char word[]) {
	}
	
	public boolean contains(const char word[]) {

	}
  public boolean containsPrefix(const char word[]) {

	}
	public void print() {
	}

}; 
