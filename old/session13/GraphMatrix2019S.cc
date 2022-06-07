#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <stack>
using namespace std;

constexpr double inf = std::numeric_limits<double>::infinity();

class MatrixGraph {
private:
	int V;
	double* w;
public:
	MatrixGraph(int V) : V(V) {
		w = new double[V*V];
		for (int i = 0; i < V*V; i++)
			w[i] = inf;
	}
	void setEdge(int from, int to, double newW) {
		w[from * V + to] = newW;
		w[to * V + from] = newW;
	}

	double getW(int from, int to) {
		return w[from * V + to];
	}

	friend istream&  operator >>(istream& s, MatrixGraph& g) {
		s >> g.V;
		string val;
		for (int i = 0; i < g.V; i++) {
			for (int j = 0; j < g.V; j++) {
				s >> val;
				if (val == "inf")
					;//leave it infinity!g.setEdge(i,j, inf);
				else
					g.setEdge(i,j, std::stod(val));
			}
		}
		return s;
	}
	
	void floydWarshall() const {
		double* dist = new double[V*V];
    for (int i = 0; i < V*V; i++) //O(V^2)
			dist[i] = w[i];				
		for (int i = 0; i < V; i++)  //O(V)
			dist[i*V+i] = 0;
    for (int i = 0; i < V; i++) //O(V^3)
			for (int j = 0; j < V; j++)
				for (int k = 0; k < V; k++)
					if (dist[i*V+j] > dist[i*V+k] + dist[k*V+j])
						dist[i*V+j] = dist[i*V+k] + dist[k*V+j];

		// print the coefficients
    for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
				cout << dist[i*V+j] << '\t';
			cout << '\n';
		}
		delete [] dist;
}

	void dfs(int v0) {
		bool* planned = new bool[V];
		dfs(v0, planned);
		delete [] planned;
	}
		
	void dfs(int v0, bool* planned) { //O(V^2)
		stack<int> toVisit;
		for (int i = 0; i < V; i++) //O(V)
			planned[i] = false;

		toVisit.push(v0);
		planned[v0] = true;

		while (!toVisit.empty()) {
			int v = toVisit.top();
			toVisit.pop();
			cout << v << '\t';
			for (int i = 0; i < V; i++) // O(V)
				if (getW(v, i) < inf && !planned[i]) {
					toVisit.push(i);
					planned[i] = true;
				}
		}
	}
	
	bool isConnected() {
		bool* planned = new bool[V];
		dfs(v0, planned);

		bool connected = true;
		for (int i = 0; i < V; i++)
			if (planned[i] == false) {
				connected = false;
				break;
			}
				
		delete [] planned;
    return connected;
	}
};


int main() {
	MatrixGraph g(5);
	//	g.setEdge(1, 5, 0.5);
	//	g.setEdge(1, 4, 1.5);
	ifstream f("test.gr");
	f >> g;
	g.floydWarshall();
	g.dfs(0);
}
	
