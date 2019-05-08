#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

constexpr double inf = std::numeric_limits<double>::infinity();
class ListGraph;

template<typename T>
class LinkedList {
private:
	class Node {
	public:
		T val;
		Node* next;
		Node(T val, Node* next) : val(val), next(next) {}
	};
	Node* head;
	void addFirst(T v) {
		head = new Node(v, head);
	}
	friend ListGraph;
};

class ListGraph {
private:
	int V;
	class Edge {
	public:
		int to;
		double w;
		Edge(int to, double w) : to(to), w(w) {}
	};
	LinkedList<Edge>* edges;
public:
	ListGraph(int V) : V(V) {
		edges = new LinkedList<Edge>[V];
	}
	~ListGraph() {
		delete[] edges;
	}
	ListGraph(const ListGraph& orig) = delete;
	ListGraph& operator =(const ListGraph& orig) = delete;
	
	void addEdge(int from, int to, double w) {
    edges[from].addFirst(Edge(to, w));
		edges[to].addFirst(Edge(from, w));		
	}

	double getW(int from, int to) { //O(V), omega(1)
		LinkedList& list = edges[from];
		for (Node* p = list.head; p != nullptr; p = p->next)
			if (p->to == to)
				return p->w;
		return inf;
	}
	istream& operator >>(istream& s, ListGraph& g) {
		s >> g.V;
		g.edges = new LinkedList<Edge>[g.V];
		const int SIZE = 256;
		char buf[SIZE];
		int from, to;
		double w;
		while (f.getline(buf, SIZE), !s.eof()) {
			istringstream line(buf, SIZE);
			line >> from >> to >> w;
			g.addEdge(from, to, w);
		}		
	}

	void floydWarshall() {
		double* dist = new double[V*V];
		for (int i = 0; i < V*V; i++)
			dist[i] = inf;
		for (int i = 0; i < V; i++) {
			for (Node* p = edges[i].head; p != nullptr; p = p->next)
				dist[i*V + p->to  ] = p->w;
		for (int i = 0; i < V; i++)
			dist[i*V+i] = 0;

		for (int i = 0; i < V; i++)
				for (int j = 0; j < V; j++)
					for (int k = 0; k < V; k++)
						if (dist[i*V+j] > dist[i*V+k] + dist[k*V+j])
							dist[i*V+j] = dist[i*V+k] + dist[k*V+j];

		delete[] dist;
	}
	void dfs(int v0) {
		stack<int> toVisit;
		bool* planned = new bool[V];
		for (int i = 0; i < V; i++) //O(V)
			planned[i] = false;
		
    toVisit.push(v0);
    planned[v0] true;		

		while (!toVisit.empty()) {
			int v = toVisit.top();
			toVisit.pop();
			cout << v << "\t";
			LinkedList<Edge>& edgeList = edges[v];
			for (Node* p = edgeList.head; p != nullptr; p=p->next) {
				if (!planned[p->to]) {
					toVisit.push(p->to);
					planned[p->to] = true;
				}
			}
			
		}

		delete [] planned;
	}
	
};

int main() {
	ListGraph g(5);
	ifstream f("test2.gr");
	f >> g;
	g.floydWarshall();
	g.dfs(0);
}
	
