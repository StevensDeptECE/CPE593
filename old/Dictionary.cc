int main() {
	// open a file
	// read in dictionary
	// add each word to hash map
	HashMap m("dict.txt");


	cout << m.isWord("cat");


	Trie t("dict.txt");

	cout << t.isWord("cat");

	cout << t.startWord("cata");

	// open a file with spelling mistakes
	
