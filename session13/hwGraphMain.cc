#include <iostream>
#include <CSR.hh>

int main() {
	CSR g("hwgraph.dat");
	//	g.save("graph.bin");

	//	CSR g2;
	//	g2.load("graph.bin");

	//	cout << g2 << '\n';

	g.DFS(0); // should print the graph depth first search starting with vertex 0
	cout << '\n';
	
	g.BFS(0); // should print the graph depth first search starting with vertex 0
	cout << '\n';

	float* costs = new float[6*6]; // this is hardcoded. CHEATING!

	g.floydWarshall(costs);
	int c = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++, c++)
			cout << costs[c++];
		cout << '\n';
	}
	delete[] costs;
}
	
