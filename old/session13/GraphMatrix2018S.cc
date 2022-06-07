#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MatrixGraph {
private:
	static constexpr double BIG = 1e100;
	double* w;
	int V;
public:
	MatrixGraph(const char filename[]) {
		ifstream f(filename);
		f >> V;
		w = new double[V*V];
		int c = 0;
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++, c++)
				f >> w[c];
	}
	~MatrixGraph() {
		delete [] w;
	}
	MatrixGraph(const MatrixGraph& orig) = delete;
	MatrixGraph& operator =(const MatrixGraph& orig) = delete;
	double adjacent(int i, int j) const {
		return w[i * V + j];
	}
	bool isAdjacent(int i, int j) const {
		return adjacent(i,j) != BIG;
	}
	void dfs(int v0) {
		bool visited[V] = { false };
		dfs(v0, visited);
	}
private:
	void dfs(int v, bool visited[]) {
    cout << v;
		visited[v] = true;
		for (int v2 = 0; v2 < V; v2++) {
			if (isAdjacent(v, v2) && !visited[v2])
				dfs(v2, visited);
		}
	}
	friend ostream& operator <<(ostream& s, const MatrixGraph& g) {
		for (int i = 0; i < g.V; i++) {
			for (int j = 0; j < g.V; j++)
				cout << g.adjacent(i,j) << "\t";
			cout << "\n";
		}
		return s;
	}

	void dfsIterative(int v0) {
		stack<int> todo;
		todo.push(v0);
		bool visited[V] = {false};
    visited[v0] = true;
		while (!todo.empty()) { //O(V)
      int v = todo.top();
			cout << v;
			todo.pop();
			for (int v2 = V-1; v2 >= 0; v2--) { //O(V)
				if (isAdjacent(v, v2) && !visited[v2]) {
     			todo.push(v2);
					visited[v2] = true;
				}
		}
	}
	
};

int main() {
	MatrixGraph g("graph.dat");
	cout << g << "\n";

	g.dfs(0);
	g.dfsIterative(0);
	g.bfsIterative(0);

	//	cout << g.isConnected() << "\n";
}
