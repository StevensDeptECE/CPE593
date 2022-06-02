# Analysis of Complexity
Hello! This week's topic is the basis for everything this semester: analyzing code and trying to figure out how long it takes as the problem grows.

In order to simplify analysis we make some assumptions:

1. All memory is accessed at the same speed (random access). There is no sequential access, and no cache. Those things do make computers faster, but only by a constant factor.
1. The speed of the computer does not matter. Computers do get faster over time, but problems do not necessarily get faster linearly. Some problems get much harder as the size grows, and others do not. It is vital to know the function governing the asymptotic growth of the problem.
1. Some statements are faster than others. For example, on most computers, multiplication takes 3-4 clock cycles, where addition takes only 1. But this doesn't matter, because it is still just a constant factor.

We will analyze a number of different cases.

1. [Individual statements and loops](#individualstatementsandloops)
1. Nested loops
1. Loops with if statements
1. Recursive functions

Each one is covered in a short video, follwed by some quick problems to practice.

[#individualstatementsandloops]
All simple statements are considered to take a single unit of time. So for example:

```
x = 3 + 2;
y = ((5*x + 9)*x + 14)*x - 7;
```

While the second statement definitely takes much longer, the difference is just a constant, and therefore does not count.

A loop is fundamentally different. The following loop is dependent on the variable n. If n grows by a factor of 2, the loop takes twice as long.

```
for (int i = 1; i <= n; i++) {

}
```

As the variable n grows large, the constant increasingly doesn't matter. It does not matter whether this loop starts from 0, 1 or 5. If n=1,000,000 then the difference is tiny.

The simplified measure of the length of a computation is called the order of the computation, big-O for short.

The following loops all have O(n)

```
for (int i = 5; i < n; i++) {

}

for (int i = -2; i <= n; i += 2) {

}

for (int i = 0; i < 2*n; i++) {

}
```

Why is a loop that goes to 2n also O(n)? Because constant factors don't matter. If you have a computer twice as fast, it will execute the loop in half the time. If you have a computer that is slow, it might take another factor of 2. What matters is not the absolute amount of time, but how fast the computation grows as n increases, and that is linear. So if n doubles, on whatever computer you have, the time will double as well.

Sequential loops are additive. The computer first has to process the first loop, then the second.

```
for (int i = 1; i <= n; i++) { //O(n)
}
for (int i = 1; i <= n; i++) { //O(n)
}
```

O(n) + O(n) = O(2n) = O(n)
