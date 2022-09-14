int fact(int n) { // O(2n) = O(n)
	if (n < 0)
		return 1;
	return n * fact(n-1);
}

int fibo(int n) { // O(2^n) 
	if (n < 2)
		return 1;
	return fibo(n-1) + fibo(n-2);
}

int main () {

	int z = fibo(10); // fibo(9) --> fibo(8) ... 2

	//                            10
	//                           9                    8
	//                          8
	//                         7
	//                        6
	//                       5
  //                      4 = 2 +  fibo(3)          
		//                   fibo(3) = 1 + 1 = 2
		//                  2 = 1  --> fibo(1) = 1
