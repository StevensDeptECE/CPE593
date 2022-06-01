#include <iostream>
#include <string>
using namespace std;

template<typename Record, typename Key, Key Record::*key>
class BTree {
	constexpr static int maxChildren = 20;
  struct Node {
		bool leaf;
		int  n;
		Record keys[maxChildren];
		//		Node* next[n];
    Node() : leaf(true), n(0) {}
	};
	Node* root;
public:
	BTree() : root(new Node) {

	}

	void insert(const Record& r) {
		if (r.*key > root->keys[0].*key) {
			cout << "holy crap it works";
		}
	}
	
};

class Student {
public:
	int id;
	string firstName;
	string lastName;
};

int main(){
  BTree<Student, int, &Student::id> students;
	students.insert({1, "Zachary", "Fazal"});
	students.insert({1, "Dov", "Kruger"});


  BTree<Student, string, &Student::firstName> studentsByFirstName;

}
