for (int i = 0; i < n; i++)  // O(n)
	;

for (int i = 1; i < n; i++)  // n-1 = O(n)
	;

for (int i = 7; i < .001*n; i+= 13) //O(n)
	;


// nested loops multiply
for (int i = 0; i <= n; i++) //O(n)
	for (int j = 0; j <= n; j++) //O(n)
		;

//m/2*n = O(mn)
for (int i = 0; i <= n; i++) //O(n)
	for (int j = m/2; j <= m; j++)  //O(m)
		;

// 2n = O(n)
for (int i = 0; i < n; i++)
	;
for (int i = 0; i < n; i++)
	;

// m+n = O(max(m,n))
for (int i = 0; i < n; i++)
	;
for (int i = 0; i < m; i++)
	;

//
for (Int i = 0; i < n; i++) //O(n)
	for (int j =  i; j < n; j++) // n + (n-1) + (n-2) ... + 1 = n(n+1)/2
		;



