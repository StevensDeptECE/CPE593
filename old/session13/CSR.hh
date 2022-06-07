#pragma once

class CSR {
public:
	typedef uint32_t VertexType;
	typedef float WeightType;
private:
	VertexType V, E;
	std::vector<VertexType> startIndex;
	std::vector<VertexType> adjacency;
	std::vector<WeightType> w;
public:
	CSR(const char filename[]); // load ascii format (slow)


	bool isAdjacent(VertexType from, VertexType to) const {
    for (VertexType i = startIndex[from]; i < startIndex[from+1]; i++)
			if (adjacency[i] == to)
				return true;
		return false;
	}

	template<typename T>
	void allAdjacent(VertexType from, VertexType to, T f) const {
    for (VertexType i = startIndex[from]; i < startIndex[from+1]; i++)
			f(from,to);
	}

#if 0
	//TODO: not quite ready for prime time
  void load(const char filename[]) {
		ifstream f(filename);
    f.read(&V, sizeof(VertexType));
		f.read(&E, sizeof(VertexType));
		startIndex.reserve(V+1);
		adjacency.reserve(E);
		w.reserve(E);
    f.read((char*)&startIndex[0], V*sizeof(VertexType));
		f.read((char*)&adjacency[0], E * sizeof(VertexType));
		f.read((char*)&w[0], E * sizeof(WeightType));
	}

	void save(const char filename[]) {
		ofstream f(filename);
		f.write((char*)&V, sizeof(uint32_t) );
		f.write((char*)&E, sizeof(uint32_t));
    f.write((char*)&startIndex[0], startIndex.size()*sizeof(VertexType));
		f.write((char*)&adjacency[0], adjacency.size() * sizeof(VertexType));
		f.write((char*)&w[0], w.size() * sizeof(WeightType));
	}

#endif
	
	void DFS(int v);
	void BFS(int v);
	void floydWarshall(float* costs);
	//  void prim();
	friend ostream& operator <<(ostream& s, const CSR& csr);
};
