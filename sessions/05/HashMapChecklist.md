# Hashmap CHecklist

1. If the key is a sequential integer starting from 0, use an array

1. If the key is a sequential integer [a,b] = [10^9, 10^9+50]
 use an array index[i-a]

1. IF the key is a nonsequential, a, a+k, a+2k, ...
   100000 100000.5 100001 100001.5 ...
   scale it   [(i - 100000)*2]

1. If it's a float DON'T USE HASHING!!!
    1.23456   1.2345600001 roundoff error floating point numbers
    are almost NEVER EQUAL

1. if it's discrete, all over the place, HUGE, use hashing
