// https://drive.google.com/file/d/1nob6vwHJvyibckOQ1WL5dAQtTZOJ_B8G/view?usp=sharing

int main() {
	// open the dictionary file
	ifstream f("dict.txt");
  Dictionary dict(f); // read in all words into your hash table
	// Dictionary should use Hashmap linear chaining
	dict.hist(); // generate a histogram
	// print out  500k bins
	//   how many bins has 0 elements    295k
	//   how many bins have 1 elemsnt    200k
	//   how many 2,                       4k
	//   3                                 800
	//   , 4, 5, 6, 7, 8                   200
	//   how many bins have 9 or more      0

	ifstream spell("spell.txt");
	// read in each word from the spell check file
	// if it is NOT in the dictionary, print it out
}
