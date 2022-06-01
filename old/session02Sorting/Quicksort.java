public class Quicksort {
    public static void quicksort(int[] x, int L, int R) {
	if ( L >= R)
	    return;

	int i = L, j = R;

	// 	partition into two halves
	while (i < j) {
	    while (x[i] <= pivot)
		i++;
	    while (x[j] > pivot)
		j--;
	    swap(x[i], x[j]);
	}

	// i == j somewhere in the middle
	quicksort(x, L, i);
	quicksort(x, i+1, R);


    }

}
