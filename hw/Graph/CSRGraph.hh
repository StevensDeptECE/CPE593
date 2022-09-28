#pragma once
#include <vector>

constexpr double INF = std::numeric_limits<double>::infinity();

class CSRGraph {
private:
	class Edge {

	};
	std::vector<uint32_t> startIndex;
	std::vector<uint32_t> to;
	std::vector<double> w;
public:
	CSRGraph(const char filename[]) {
		//TODO:
	}
	~CSRGraph() {
		//TODO:
	}
	CSRGraph(const CSRGraph& orig) = delete;
	CSRGraph& operator =(const CSRGraph& orig) = delete;
	double isAdjacent(uint32_t i, uint32_t j) {
		//TODO: find startIndex[i]. look through to[] until you find j
		// if you do, return corresponding w[] otherwise return INFINITY
		return 0; // return the w[...]
	}
	class Iterator {
		CSRGraph* parent;
    int from;
		int current;
	public:
		Iterator(CSRGraph* m, uint32_t from) :
		bool hasNext() const {
			return ____;
		}
		void operator ++() {

		}
	};

	Iterator getIterator(uint32_t from) {
		//TODO

	}
};
