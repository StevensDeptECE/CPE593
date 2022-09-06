#include <iostream>
#include <fstream>
#include <cstdint>

/*
	Implement methods add(), get() and hist() for both types of hashmap
	You must read the file dict.txt in the current directory.
	DO NOT put in a path, that will only work on your computer.

https://drive.google.com/drive/folders/0Bwxfq4Y7f7vkTkZnVEFEcXVEWmc?resourcekey=0-mOXByawNd1BgAZIqFmdGzQ&usp=sharing
*/

int main() {
	constexpr int n = 1000000;
	HashMapLinearProbing m1(n);
	HashMapLinearChaining m2(n);

	int count = 0;
	//read in the dictionary (213k words)
	ifstream dict("dict.txt"); ...
	{// write your loop!
		m1.add(word, count); // each word has a unique id number
		m2.add(word, count);
		count++;
	}
	int id;

	cout << "\n\nLinear probing\n";
	const char words[] = {"apple", "bear", "cat", "dog", "arggg",
												"juwqehtrkqwejhr"};
	for (int i = 0; i < sizeof(words[i])/sizeof(char*); i++) {
		bool found = m1.get(words[i], &id);
		cout << "word " << words[i] << " " << found << "id=" << id << '\n';
	}
	// print out the histogram showing count of inserts taking 1, 2, 3, ... 9+
	m1.hist();
	
	cout << "\n\nLinear chaining\n";
	for (int i = 0; i < sizeof(words[i])/sizeof(char*); i++) {
		bool found = m2.get(words[i], &id);
		cout << "word " << words[i] << " " << found << "id=" << id << '\n';
	}
	// print out the histogram showing bins of size 0, 1, 2, 3, ... 9+
	m2.hist();
}
