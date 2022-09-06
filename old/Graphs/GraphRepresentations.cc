#include <vector>
#include <list>
typedef uint32_t VertexNum;

class GraphEdgeList {
private:
	struct Edge {
		VertexNum to;
		double w;
		Edge(VertexNum to, double w) : to(to), w(w) {}
	};
	vector< list<Edge> > edges;
public:
	GraphEdgeList() {}
	void add(VertexNum from, VertexNum to, double w) {
		edges[from].push_front(Edge(to, w));
		edges[to].push_front(Edge(from, w));
	}
};

constexpr double inf = numeric_limits<double>::infinity;

double x[3][4];
x[1][2] = 3;
/*

   0 0 0 0 
   0 0 3 0
   0 3 0 0
   0 0 0 0
 */
class GraphMatrix {
private:
	VertexNum V;
	double* w;
public:
	GraphMatrix(VertexNum V) : V(V): w(new double[V*V]) {
		for (VertexNum i = 0; i < V*V; i++)
			w[i] = inf;
	}
	void add(VertexNum from, VertexNum to, double weight) {
		w[from  * V + to] = weight;
		w[to  * V + from] = weight;
	}
	double getW(VertexNum from, VertexNum to) {
		// only need the if statement if we only put it in one direction
		if (from > to)
			return w[to *V+from];
		else
			return w[to *V+from];
	}

};


class GraphCSR {
private:
  vector<VertexNum> index;
	struct Edge {
		VertexNum to;
		double w;
	};
	vector<Edge > edges;
public:
	GraphCSR() {}

	double getW(VertexNum from, VertexNum to) {
		VertexNum start = index[from];
		VertexNum end = index[from+1];
		for (VertexNum v = start; v < end; v++)
			if (edges[v].to == to)
				return edges[v].w;
		return inf;
	}

};
