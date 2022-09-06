class EdgeListGraph {
private:
	int V;
	vector< list<int> > edgeList;

public:
	EdgeListGraph(int V) : V(V) {
		edgeList.reserve(V);
		for (int i = 0; i < V; i++)
			edgeList.push_back(list<int>());	 
	}
	void add(int v1, int v2) {
    edgeList[v1].push_back(v2);
		edgeList[v2].push_back(v1);

		// or...
		if (v1 < v2)
			edgeList[v1].push_back(v2);
		else
			edgeList[v2].push_back(v2);
	}

	bool isAdjacent(int v1, int v2) {
    for (e : edgeList[v1])
			if (e == v2)
				return true;
		return false;
		// or

		if (v2 < v1) {
			swap(v1,v2);
		}
    for (e : edgeList[v1])
			if (e == v2)
				return true;
		return false;
	}

	void dfs(int v) {
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;
		dfs2(v, visited);

		delete [] visited;
	}
	void dfs2(int v, bool visited[]) {
    visited[v] = true;
		cout << "visiting " << v << '\n';
		for (int i = 0; i < V; i++)
			if (!visited[i] && isAdjacent(v,i))
				dfs2(i, visited);
	}
};
