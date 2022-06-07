#include <string>

using namespace std;

int lcs(string A, string B)
{
	// must be static variable for dynamic programming!
	// static int *memo= new int[m*n];
	if (A.length() == 0 || B.length() == 0)
		return 0;        //O(1)
	
	if (A[0] == B[0])
		return 1 + lcs(A.substr(1), b.substr(1));    //O(min(len(A),len(B))
  return max(lcs(A.substr(1),B), lcs(A,B.substr(1)));    //O(2^n)
}
