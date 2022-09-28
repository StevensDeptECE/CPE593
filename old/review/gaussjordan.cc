 
1   2    3       1      22
2   1    2   *   3 =    15 
-1  2    1       5      10

	 
1   2    3       x      22
2   1    2   *   y =    15 
-1  2    1       z      10

	create augmented matrix
1   2    3    22
2   1    2    15 
-1  2    1    10

		create augmented matrix
1   2    3    22
0   -3   -4   -31 
0   4    4    54


partial pivoting


	
rowreduction( )
	for i = 0; i < n-1; i++) {
    s = -m(i+1,i)/m(i,i)
		for k=i+1; k < n; k++) {
  		m(k,i) = 0
	  	for j = 1; j <= n; j++ {
 		    m(k,j) = m(k,j) + s * m(i,j)
		  }
	  }
  }
}

					
