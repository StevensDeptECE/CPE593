void partialquicksort(x, L, R ) {
	if (i - L > k)
		partialQuicksort(x, L, i);
	if (R - i+1 > k)
		partialQuicksort(x, i+1, R);
}

knuthquicksort(int x[], int n) {
	partialquicksort(x, 0, n-1); // k = minimum size = ???

	// k = 2 quicksort,  k = 2000  insertion sort is doing too much
	insertionsort(x);
}

testprocedure() {
	int[] r = generatenrandomnumbers();

	foreach trial
		// golden mean search determines which k to try
		int[] copy = r; // copy the array
	knuthQuicksort(copy); // with k = ???
}

/*
	output should be:

	k = 2  took: xxx seconds
  k = 1000 took: yyy seconds
  k = 425 took aaa seconds
  k = 575 took bbb seconds
	...


	best time k = ttt took xxx seconds
*/
	
