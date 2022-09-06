
class SerializableHashMap {
private:
	char* words; // Java: StringBuilder words;
	struct Node {
		uint32_t key; // offset into words
		int val;
		uint32_t next; // offset into the nodes table
	};
	Node** table;
	Node* nodes;

public:

int main() {
	// 1. read a dictionary file
	SerializableHashMap m("dict.txt"); // Java: m = new SerializableHashMap("dict.txt");
	// read in each word and add to the dictionary

	// store all teh strings into words
	// words = "ahh,apple,dictionary,dov,hello,in,testing,words

	// table = { null, null, null, null, null, null, null null}
	// really, table = {0, 0, 0, 0, 0, 0, 0, 0}
	// really, table = {0, 2, 0, 0, 1, 0, 4}
	// nodes = {zero is empty}     {aah, 1, null}, {apple, 2, null}, 
	//{dictionary,3, null} , {dov, 4, 3 }, {hello, 5, null}


	//	write out dictionary:
	// write out all words [4 byte length]ahh,apple,dictionary,dov,....
	// write out all nodes offset (start of word),
	// write table
}
