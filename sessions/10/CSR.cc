#include <iostream>
#include <vector>

class CSR {
private:
	std::vector<uint32_t> startPos;
	std::vector<uint32_t> adjacenct;
	std::vector<double> w;

public:

	bool is_adjacent(uint32_t i, uint32_t j) const {
		for (uint32_t k = startPos[i]; k < startPos[i+1]; k++) { // O( V )
			if (adjacent[k] == j) // omega(1)
				return true;
		}
		return false;//O(V)
	}

	template<typename Func>
	void all_adjacent(uint32_t i, Func f) {
		for (uint32_t k = startPos[i]; k < startPos[i+1]; k++) { // O( V )
			f(i,k);
		} // omega(1)
	}

};
