#include "MatrixGraph.hh"
//#include "EdgeListGraph.hh"
//#include "CSRListGraph.hh"

#define Graph MatrixGraph

//#define Graph CSRGraph
int main() {
	Graph g("graph1.txt");
	int V = g.getVertexCount();
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			cout << "adjacency: " << i << "," << j << "==>" <<
				g.isAdjacent(i,j) << '\n';
	cout << "\n\n\n";
	for (int i = 0; i < V; i++) {
		cout << i << ": ";
		
    for (Graph::Iterator j = getFirstAdjacency(i); j.hasNext(); ++j) {
			cout << j.getWeight() << ' ';
		}
}
