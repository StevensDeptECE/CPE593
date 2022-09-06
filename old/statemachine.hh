#include <vector>

class FSM {
private:
  typedef uint32_t NextState[256];
	std::vector<NextState> nextStates;
	uint32_t current;
public:
	// dog|cat
	FSM(const char regex[]) {
		current = 0;
	}
	void process(char c) {
		current = nextStates[current][c];
		if (func != nullptr)
			func();
	}
};
