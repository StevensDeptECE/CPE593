binarySearch(a, target){
	L = 0;
	R = length(a) - 1;
	while(L <= R){
		mid = (L+R)/2;
		if(a[mid] > target)
			R = mid - 1;
		else if(a[mid] < target)
			L = mid + 1;
		else
			return mid
	
	}
	return -1
}
/*
	//		14
	//2 4 6 8 10 12 14
	  L     mid     R
	//8 10 12 14
	  L mid R
	//12 14
	L     R
	mid
	//12 14
*/