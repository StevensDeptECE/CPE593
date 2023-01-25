#include <vector>
#include <iostream>

class edge {
private:
	int to;
	double w;
public:
	edge(int to, double w) : to(to), w(w) {}
};

class graph {
private:
	std::vector<std::vector<edge> > edges;
public:
	graph(int V)

};
