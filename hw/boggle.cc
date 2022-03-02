class Boggle {
private:
	//board
	// letters used so far (boolean array)
	// keep all parameters that don't change in the object

	bool is_a_solution() {
		return true;// if this solution works
	}
	void backtrack(letter_position ) {
		if (is_a_solution())
			process_solution();
		if (filter_bad()) {
			// RATEF 
			// mark all letters deeper no longer used (mark F not used
			return;
		}

		// try all adjacent letters  THAT ARE NOT ALREADY USED
		backtrack(letter_position);

	}
};

	 

int main() {
	// read in boggle board
	// for each element on the board
	// mark all elements unread
	/*
5
R    A    E    F    R
Q    T    N    S    I
M    O    E    A    M
T    A    P    L    O
A    S    O    G    U
	*/
	// R [mark read] A [mark read] E [FAIL]
	// clear all marks
	// R [mark read] A [mark read] T (word!)
	// check if any words start with RAT, if so keep going
	// RATE, RATEF (no) RATES (yes) RATESR (no)
