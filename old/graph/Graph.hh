class MatrixGraph {
private:
	double* w;
	int V; // V*V
	void DFS_internal(int v0, bool visited[]) {
		cout << v0;
		visited[v0] = true; // never visit this again

		int adj;
		for (adj = getFirstAdjacency(v0); adj >= 0; adj = getNextAdjacency(v0)) {
      if (!visited[adj]) {
        DFS_internal(adj, visited);				
			}
		}
	}
public:
	double getAdjacent(int from, int to)		{
		//TODO!
		return 0;
	}
	void DFS_recursive(int v0) {
    bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false; // no vertex has been visited YET
		DFS_internal(v0, visited);
		delete [] visited;
	}

	void DFS(int v0) {
    bool* planned = new bool[V];
		for (int i = 0; i < V; i++)
			planned[i] = false; // no vertex has been visited YET
		stack<int> todo;
		todo.push(v0); // first vertex must be visited
		while (!todo.empty()) {
			int v = todo.top();
			todo.pop();
      cout << v; //
			for (int i = 0; i < V; i++)
				if (adjacent(v, i) && !planned[i]) {
          todo.push(i);
					planned[i] = true; // don't push on teh stack again
				}
		}
		
};
