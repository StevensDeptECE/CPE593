#include <iostream>
#include <stack>
using namespace std;

class GraphList {
private:
  //in Java: Double.POSITIVE_INFINITY
    public static constexpr double INFINITY = 1.0 / 0.0;
  class Edge {
  public:
    int to;
    double w;
    Edge* next;
    Edge(int to, double w, Edge* next) : to(to), w(w), next(next) {}
  };
  Edge** edges;
  int V;
public:
  GraphList(int V) : V(V) {
    edges = new Edge*[V];
  }
  ~GraphList() {
    Edge** p = edges;
    for (int i = V; i > 0; i--, ++p) {
      // delete the linked list...
      Edge* temp;
      for (Edge* q = *p; q != nullptr; q = temp) {
	temp = q->next;
	delete q;
      }
    }
    delete [] edges;
  }
  void setEdge(int i, int j, double w) {
    for (Edge* e = edges[i]; e != nullptr; e = e->next) {
      if (e->to == j) {
	e->w = w;
	return;
      }
    }
    edges[i] = new Edge(i,j, w, edges[i]); // addFirst
  }
  
  double adjacent(int  i, int j) { //O(V)
    Edge* n = edges[i];
    if (n == nullptr)
      return INFINITY;
    for ( ; n != nullptr; n=n->next)
      if (n->to == j)
	return n->w;
    return INFINITY;
  }
  void DFS(int v) {
    bool visited[V];
    for (int i = 0; i < V; i++)
      visited[V] = false;
    stack<int> todo;
    visited[v] = true; 
    todo.push(v);
    while (!todo.empty()) {
      int v = todo.back();
      todo.pop_back();
      cout << v;
      for (Edge* p = edges[v]; p != nullptr; p = p->next) {
	int v2 = p->to;
	if (!visited[v2]) {
	  stack.push_back(v2);
	  visited[v2] = true;
	}
      }
    }
  }
};
