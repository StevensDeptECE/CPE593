#include <iostream>
#include <word>
using namespace std;

int main() {
  ifstream words("dict.dat");
  string word;
  HashMapLinearChaining dict1(50000); // initial size
  while (!words.feof()) {
    words >> word;
    dict1.add(word); // add the word to the dictionary
  }
  dict1.hist(); // display histogram
  ifstream spell("words.dat");
  string s;
  while (!spell.eof()) {
    spell >> s;
    if (dict1.contains(s))
      cout  << s << " found!\n";
    else
      cout << s << " not found!\n";
  }
}
  
