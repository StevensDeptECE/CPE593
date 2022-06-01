#include <vector>

class CSRGraph {
private:
	struct To {
		uint32_t dest;
		float w;
	};
	int V; // the number of vertices
	std::vector<uint32_t> startIndex;
	std::vector<To> to;
	void dfs(int v, bool visible[]) {
		visible[v] = true;
		cout << v;
		uint32_t end = startIndex[v+1];
		for (uint32_t i = to[startIndex[v]]; i < end; i++) {
			if (!visited[i])
				dfs(i, visited);
		}
	}
public:
	CSRGraph(const char filename[]) {

	}
	void dfs(int v) {
		bool visible[startIndex.size()] = {false};
    dfs(v, visible);
	}
	
	void iterativeDFS(uint32_t v) {
		bool scheduled[startIndex.size()] = {false};
		stack<uint32_t> todo;
		todo.push_back(v);
		scheduled[v] = true;
		while (!todo.empty()) {
			v = todo.back();
			todo.pop_back();
			cout << v;
			for (uint32_t i = startIndex[v]; i < startIndex[v+1]; i++)
				if (!visited[i]) {
					todo.push_back(i);
					scheduled[i] = true;
				}
		}
	}

	void iterativeBFS(uint32_t v) {
		bool scheduled[startIndex.size()] = {false};
		queue<uint32_t> todo;
		todo.push_back(v);
		scheduled[v] = true;
		while (!todo.empty()) {
			v = todo.front();
			todo.pop_front();
			cout << v;
			for (uint32_t i = startIndex[v]; i < startIndex[v+1]; i++)
				if (!visited[i]) {
					todo.push_back(i);
					scheduled[i] = true;
				}
		}
	}

	void bruteForceTSP(uint32_t v) { // 5 6 7 8 9 0 1 2 3 4
		vector<uint32_t> path;
		for (uint32_t i = v; i < V; i++)
			path.push_back(i);
		for (uint32_t i = 0; i < v; i++)
			path.push_back(i);
		while (permute(path)) { // O(V!)
			//calculate cost of this path
			double pathcost = 0;
			for (int i = 0; i < V; i++) { //O(V)
				double w = getW(permute[i], permute[i+1]); //O(V)
				if (isinf(w))  {
					pathcost = w;
					break;
				}

		}
	}
};

using namespace std;


int main() {
	CSRGraph g("graph1.txt");
	//	CSRGraph g2 = CSRGraph::fastLoad("graph1.bin");

	g.dfs(0);
