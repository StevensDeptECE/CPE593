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

// n(n+1)/2 = O(n^2)
for (Int i = 0; i < n; i++) //O(n)
	for (int j =  i; j < n; j++) // n + (n-1) + (n-2) ... + 1 = n(n+1)/2 = (n^2 + n)/2
		;

for (Int i = 0; i < n; i++) //O(n)
	for (int j =  0; j < i; j++) //1 + 2 + 3 + .. + n-1 = n(n-1)/2 = (n^2 - n)/2
		;


for (int i = 1; i < sqrt(n); i++) { // O(
}

for (int i = 1; i < n; i *= 2) // log2(n) = O(log(n))
	;

for (int i = 0; i < n; i *= 2) // infinite loop!
	;

// 1, 4, 13, 40, 
for (int i = 0; i < n; i = i * 3 + 1) // log3(n) = O(log(n))
	;

// O(n log n)
for (int i = 0; i < n; i++) //O(n)
	for (int j = 1; j < i; j *= 2) // log2(1) + log2(2) + log2(3) + ... = O(log(n))
		;

double fibo(int n) {
	if (n <= 2) //O(1)
		return 1;
	return fibo(n-2) + fibo(n-1);

}

// 86400 seconds = 1 day
// 31.5 million seconds = 1 year











