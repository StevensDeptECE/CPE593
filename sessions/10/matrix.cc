class matrixgraph {
private:
	int V;
	double *w; // V*V weights
public:
	double& operator ()(int r, int c) { return w[r * V + c]; }
	double operator () const (int r, int c) { return w[r * V + c]; }
	matrixgraph(uint32_t V) : V(V), w(new double[V*V]){
		for (uint32_t i = 0; i < V*V; i++)
			W[i] = 0;
	}
	~matrixgraph() {
		delete [] w;
	}
	matrixgraph(const matrixgraph& orig) = delete;
	matrixgraph& operator =(const matrixgraph& orig) = delete;
	bool is_adjacent(uint32_t i, uint32_t j) const {
		return is_infinity(w[i * V + j]);
	}
	
	template<typename Func>
	void all_adjacent(uint32_t i, Func f) const {
		for (uint32_t k = 0; k < V; k++) //O(V) omega(V) = theta(V)
			f(i, k);
	}
	void dfs_recursive(uint32_t v) {
		
	}
	
	
};

