#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
// in a given integer array
int kadane(const vector<int> &arr) {
	int max_so_far = 0; // largest sum found to this position
	int max_ending_here = 0; // sum of the largest sum ending at this pos

	// traverse the array of numbers
	for (int i = 0; i < arr.size(); i++) {
		// update the maximum sum of subarray "ending" at index 'i' (by adding the
		// current element to maximum sum ending at previous index 'i-1')
		max_ending_here += arr[i];

		// clamp to zero since worst case, empty subarray is bigger than neg.
		if (max_ending_here < 0)
			max_ending_here = 0;// if the number is negative, clamp to zero and don't check
		else if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;
	}

	return max_so_far;
}

int main() {
	vector<int> arr = { -2, 1, 2, -3, 4, -1, 2, 1, -5, 4 };
	cout << "The maximum sum of a contiguous subarray is " << kadane(arr);

	return 0;
}
