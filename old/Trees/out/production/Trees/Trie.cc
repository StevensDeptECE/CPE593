class Trie {
private:
	class Node {
	public:
		Node*next[26];
		bool isWord;
		Node() {
			// make sure all pointers point to nullptr
		}
	};
	Node root;
public:
	Trie() {}
	~Trie() {}
	// load the trie from a file
	void load(const char dictionary[]) {

	}
	Trie(const Trie& orig) = delete;
	Trie& operator =(const Trie& orig) = delete;
	void add(const char word[]);
	void remove(const char word[]);
  bool contains(const char word[]);	
  bool containsPrefix(const char word[]);
	void print() const;
}; 
