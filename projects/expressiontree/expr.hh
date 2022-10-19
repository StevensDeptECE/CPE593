#pragma once

/*
Abstract base class for all expression nodes
any expression must be able to be evaluated, simplified and printed
*/
class expr {
private:
	class node {
	public:
		virtual void simplify() = 0;
		virtual void print_post() = 0; // print out the expression postfix
		virtual void print_pre() = 0; // print out the expression prefix
		virtual void print_in() = 0; // print out the expression infix
	};
	node* root;
public:
	virtual double eval() = 0; // what if it does not evaluate to a number?
	virtual void simplify() = 0;
	virtual void print_post() = 0; // print out the expression postfix
	virtual void print_pre() = 0; // print out the expression prefix
	virtual void print_in() = 0; // print out the expression infix
};
