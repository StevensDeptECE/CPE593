public class Trie2020F {
  private static class Node {
		boolean isWord;
		Node[] next;
		public Node() {
			next = new Node[26];
			isWord = false;
		}
	}

	private Node root;
	
	public Trie() {
		head = new Node();
	}


	public void add(String word) { // "hello"
		Node p = root;
		for (int i = 0; i < word.length(); i++) {
			int index = word.charAt(i) - 'a';
			if (index < 0 || index >= 25)
				throw new RuntimeException ("DIE DIE DIE");
				
			Node next = p.next[index];
			if (next == null) {
				do {
					p.next[index] = new Node();
					p = p.next[index];
					i++;
				} while (i < word.length());
			} else {
				p = p.next[index];
				i++;
			}
		}
		p.isWord = true;
	}

	public boolean contains(String word) {
		Node p = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			p = p.next[c - 'a'];
			if (p == null)
				return false;
		}
		return p.isWord;
	}
	public boolean containsPrefix(String pre) {
		Node p = root;
		for (int i = 0; i < pre.length(); i++) {
			char c = word.charAt(i);
			p = p.next[c - 'a'];
			if (p == null)
				return false;
		}
		return true;
	}

	public void removeWord(String word) {
		Node p = root;
		Stack<Node> nodestack = new Stack();
		for (int i = 0; i < word.length(); i++) {
			p = p.next[word.charAt(i) - 'a'];
			nodestack.push(p);
			if (p == null)
				return;
		}
		p.isWord = false; // word removed, but nodes might be left in there...

		// work back up the tree. If all next pointers are null, then this node can be eliminated
		boolean allEmpty = true;
		Node tmp = nodestack.pop();
		int ind = word.length()-1;
		while (!nodestack.isEmpty()) {
			for (int i = 0; i < 26; i++)
				if (tmp.next[i] != null) {
					allEmpty = false;
					break;
				}
			if (allEmpty) {
				tmp = nodestack.pop();
				tmp.next[word.charAt(ind--)]= null;
			} else
				return; // if this node has at least one remaining element, then nothing further deleted
		}
	}
}
