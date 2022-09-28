#pragma once
#include <vector>

class EdgeListGraph {
private:
	class Edge {

	};
	vector< vector<Edge> > edges;
	int V;
public:
	MatrixGraph(int V) : V(V), w(new double[V*V]) {
		//TODO:
	}
	~MatrixGraph() {
		//TODO:
	}
	MatrixGraph(const MatrixGraph& orig) = delete;
	MatrixGraph& operator =(const MatrixGraph& orig) = delete;
	double isAdjacent(uint32_t i, uint32_t j) {
		//TODO:
		return 0; // return the w[...]
	}
};
