# Number theoretic algorithms notes and errata

gcd(9, 27)
   lim = min(a, b)





brute_gcd(a , b )
  lim ← min( min(a, sqrt(b)), min(sqrt(a), b))
  f o r i ← l im downto 2
    i f a mod i == 0 and b mod i = 0
      r e t u r n i
    end
  end
  return 1
end
   

gcd ( a , b )
  i f b == 0
    r e t u r n a ;
  end
  return gcd ( b , a mod b)
end


gcd(12,18) = gcd(18, 12 mod 18) = gcd(18, 12) = gcd(12, 18 mod 12) = gcd(12,6) = gcd(6, 0)

gcd(3025, 1025) = gcd(1025, 3025 mod 1025) = gcd(1025, 975) = gcd(975, 1025 mod 975) = gcd(975, 50) = 
   gcd(50, 975 mod 50) = gcd(50, 25) = gcd(25, 0)

   gcd(3025, 3023) = gcd(3023, 2) = gcd(2, )
   
reversing its way down the fibonacci sequence! worst case O(logphi(n)) = O(log n)
1 2 3 5 8 13 21 34 55
gcd(55, 34) = gcd(34, 21) = gcd(21, 13) = 


1   2    3     5    8      13   21   34    55
    2    1.5   1.6  1.625

```cpp
uint64_t gcd(uint64_t a, uint64_t b) {
  while (b != 0) {
    uint64_t temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}
```
28 =     1    2   4  |   7     14     28

```cpp
isPrime(101)
  101 mod 2 != 0
  101 mod 3 != 0
  101 mod 4 != 0
  
  ...
  isPrime(9)
  for i = 2; i <= sqrt(n)

if n = 1 billion,  how many bytes do we need?
bool * p = new bool[n];

uint64_t* p = new uint64_t[(n+63)/64]; // 1 billion / 8 = 125MB / 2 = 62.5Mb

uint64_t eratosthenes(uint64_t n, uint64_t* bits)
  uint64_t size = (n + 63) / 64 / 2;
  for (uint64_t i = 0; i < size; i++)
    bits[i] = 0xFFFFFFFFFFFFFFFFULL;
  for (uint64_t i = 3; i < n; i += 2) {
    if (test(bits, i))
      for (uint64_t j = i*i; j <= n; j += 2*i)
        clear(bits, j)
  }
```

n = 12985719285712985712987521897519827519825000000000001241241677


power(2, 9) = 
   x = 2
   prod = 1
   n=9
   if n is odd
     prod = prod * x = 1*2
   end
   x = x*x = 4
   n = n / 2 = 4
   if n is odd? NO
   end
   x = x *x = 16
   n = n/2 = 2
   if n is odd? NO
   end
   x = x*x = 256
   n = n/2 = 1
   if n is odd YES!
     prod = prod * x = 2 * 256 = 512
   end

   x=x*x = 256*256
   n=n/2 = 0
     

   (a *b) mod m  = ((a mod m) * (b mod m)) mod m


   Fermat(n, k)
     for i = 1 to k
        a = random(2, n-1)
        if powermod(a, n-1, n) != 1
          return false;
      end
      return true (probably)

p = 1000000000017
powermod(2,1000000000016, p )


d=1010110011100011111
s=27
000000000000000000000000000
     d             s


     HTTPS:// cryptography depends on RSA
     RSA depends on prime factoring being HARD   n = p * q

     factoring n is O(sqrt(n))  n = 2^8192


     quantum cryptography: Schorr's algorithm (in ref directory)
     if a quantum computer has sufficient qbits factor n in polynomial time


     Elliptic Curve Cryptography (ECC), 


     Lattice = 4 methods that were considered quantum safe one was just broken on a laptop (3 left)

     Shamir (RSA)

