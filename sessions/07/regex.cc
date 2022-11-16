class State {
private:
	uint32_t next[256];
public:

	// look up the currrent state, and return the next state
	uint32_t operator[](uint32_t i) const {
		return next[i]; 
	}
};

class FSM {
private:
	vector<State> states;
	uint32_t current;
	FSM(int n) {
		states.reserve(n);
		current = 0;
	}
	void input(uint8_t c) {
		current = states[current][c];
	}
	
};

/*
# askdhgjlasdkgjslgkj
x = 123;
if ( )


 */
int main() {
  if (regex_search(s, m, comment)) {

	} else if (regex_search(s, m, assignment) {

		} else if (regex_search(s, m, ifstatement) {

			}
			}


		}
