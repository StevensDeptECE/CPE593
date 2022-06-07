#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Expr {
protected:
	Expr* left;
	Expr* right;
  Expr* parent;
public:
	virtual void inorder() const = 0;
	virtual void preorder() const = 0;
	virtual void postorder() const = 0;
	virtual double eval() const = 0;
};

class Add : public Expr {

};
class Sub : public Expr {

};


int main() {
	// (x + 1) * (x - x)
	// x 1 + x x - *

	//   binary + - * /    unary - sqrt
	ifstream in("equations.dat");
	string line;
	while (getline(in, line)) {
		istringstream ls(line);
		string token;
		while (ls >> token) {
      cout << token << ' ';
		}
		cout << "\n\n";
	}
}
