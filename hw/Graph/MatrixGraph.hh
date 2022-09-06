#pragma once

class MatrixGraph {
private:
  double* w;
	int V;
public:
	MatrixGraph(int V) : V(V), w(new double[V*V]) {
		//TODO:
	}
	~MatrixGraph() {
		//TODO:
	}
	MatrixGraph(const MatrixGraph& orig) = delete;
	MatrixGraph& operator =(const MatrixGraph& orig) = delete;
	double isAdjacent(uint32_t i, uint32_t j) {
		//TODO:
		return 0; // return the w[...]
	}
	friend class Iterator {
		MatrixGraph* parent;
    uint32_t from;
		uint32_t current;
	public:
		Iterator(MatrixGraph* m, uint32_t from) :
			parent(m), from(from), current(0) {}
		bool hasNext() const {
			return current < parent->V;
		}
		void operator ++() {
      current++;
		}
	};
	Iterator getIterator(uint32_t from) {
		Iterator it(this, from);
		return m[
	}

};
