//Basic complexity
for(int i = 0; i < n; i++); // O(N)
for(int i = 0; i * i < n; i++); // O(sqrt(N))
for(int i = 0; i < n * n; i++); // O(N^2)
for(int i = 0; i < n; i *= 2); //O(logN)
for(int i = n; i > 0; i /= 2); //O(logN)
//loop and loop
for(int i = 0; i < n; i++) { // O(N^4)
  for(int j = 0; j < i; j++) {
    for(int k = 0; k < j * j; k += 2) ;
  }
}

for(int i = 0; i < n; i++) { // O(NlogN)
  for(int j = 0; j < n; j++) {
    j *= 2;
  }
}

for(int i = 0; i < n; i++) { //O(N)
  for(int j = 0; j > n; j++) {
  }
}

for(int i = 2; i < n; i = pow(i, 2)) { // O(loglogN)
}
