#include <iostream>
#include <word>
using namespace std;

int main() {
  ifstream words("dict.dat");
  string word;
  HashMapLinearProbing dict1(500000); // initial size
  while (!words.feof()) {
    words >> word;
    dict1.add(word); // add the word to the dictionary
  }
  dict1.hist(); // display histogram
}
  
