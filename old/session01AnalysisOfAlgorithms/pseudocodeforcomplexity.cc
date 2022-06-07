\//pseudocode for complexity

for i = 1 to n  //O(n)
{
}

for i= 5 to n-20 //O(n)
{

}

for (int i = 0; i < n; i+= 7) { //O(n)

}

for (int i = 8; i < 2*n; i += n/2) { //O(1)

}

//O(n^2)
for (int i = 0; i < n; i++) {//O(n)
  for (int j = 1; j < n; j += 5) { //O(n)

  }
}

//O(n)
for (int i = 0; i < n; i+= 4) {//O(n)
  for (int j = 1; j < n; j += 5*n) { //O(1)

  }
}


for (int i = 0; i < n; i++) {//O(n)
  for (int j = 1; j < i; i++) { // 0 + 1 + 2 + ... (n-3)+(n-2) + (n-1) + n = n(n+1)/2 = n^2 + n

  }
}

for (int i = 1; i < n; i *= 2) { //O(log n)

}

//log2(n) = loge(n) / log2(e) relationship between logs is a constant factor so we don't care!

for (int i = n; i > 1; i /= 3) { //O(log n)

}
/*
2^10 = 1024       = 1k
2^20 = 1024*1024  = 1M
2^30 = 1024^3     = 1G

n       n^2     n^3     log n       sqrt n      1
1       1       1       0           1
10      100     1000    3           3
100     10^4    10^6    7           10
10^6    10^12   10^18   20          1000
*/

for (int i = 0;  i < sqrt(n); i++) { //O(sqrt(n))

}

for (int i = 0;  i < log(n); i++) { //O(log n)

}

//O(n log n)
for (int i = 1; i < n; i++) //O(n)
  for (int j = 1; j < i; j*=2) //O(log (n))
    ;

n=300*10^6 = n log n 300*10^6 * 20 * 8
n=10^6
O(n)
for (int i = 1; i <= n; i*=2) //O(log n)
  for (int j = 1; j < i; j++) // 1 + 2 + 4 + 8 + ... + (n/2) + n
    ;
    O(n)

n(1/n + 2/n + 4/n + ... + 1) = 2n = O(n)
1 + 1/2 + 1/4 + 1/8 + ... 1/n          1+0.5+0.25+0.125 + ... = 2
{
    
} //           1+0.5+0.25+0.125 + ... = 2

//sequential loops add O(n)
for (int i = 0; i < 2*n; i++)
  ;
for (int i = 0; i < 3*n; i++)
  ;

//O(mn)
for (int i = 0; i < n; i++) //O(n)
  for (int j = 0; j < m; j++)//O(m)
  {}


// recursion
int f(n) {
    if ( n < 5) //O(1)
       return 3; // O(1)

    return 2*f(n-1); // O(n)
}

// 1, 1, 2, 3, 5, 8, 13, ...
// 1  2  3  4  5  6   7 ...
fibo(n) = fibo(n-1)+fibo(n-2)