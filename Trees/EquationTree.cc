class Expr {
public:
	virtual double eval() const = 0;
	virtual void print() const = 0;
};

class BinOp : public Expr {
private:
	Expr* left;
	Expr* right;
public:
	BinOp(Expr* left, Expr* right) : left(left), right(right) {}
};

class Add : public BinOp {
public:
	Add(Expr* left, Expr* right) : BinOp(left, right) {}
	double eval() const  {
		return left->eval() + right->eval();
	}
	void print() const {

	}
};

