# Data Structures and Algorithms summary

author: Dov Kruger

This summary show both what is in the course, and what is not but you
should consider learning afterwards if you want to continue.

This summary is designed to give you a list so you can identify what
you know and what you don't know. This does not imply that all these
areas are important for you in various jobs. That very much depends on
the job. Obviously, interviews are a gateway to jobs, and interview
questions are often more wide-ranging than the job, which can be very
focused and specific. For some common subjects, such as implementing
linked lists and graph algorithms, you should of course be prepared to
write them as these are in any data structures course and are common
interview tasks. Often, you will be expected to apply what you know to
a problem, and this can be significantly harder. Not all the topics
here are so common. Everything from compression on down can be
considered topics that you may not be able to implement in an
interview, but which you should nonetheless understand the overview
of, so that you can intelligently discuss the relative merits of
compression algorithms, know what is currently the best. This
effectively means that as a programmer, you are a consumer of these
algorithms. You need to know which to use.

<ol>
<li><details>
<summary>Analyzing complexity</summary>

 - Big O, &Omega;, theta
 - Analyzing loops to determine complexity
 - Analyzing loops with if statements to determine complexity (&Omega;)
 - Understanding &Omega; (surprising how many people miss this sometimes even if they sometimes get it right)
 - Analyzing recursion
 - Dynamic programming
 - opt Master Theorem
 - Readings
 - Homework
</details></li>

<li><details>
<summary>Dynamic Arrays</summary>

- Abstract list operations
- Bad Dynamic Arrays: complexity of operations
- Dynamic Arrays that grow by doubling in capacity
- Readings
- Homework
</details></li>

<li><details>
<summary>Linked Lists, Stacks and Queues</summary>

- Four types of Linked Lists
- Singly Linked List with head
- Singly Linked List with head and tail
- Doubly Linked List with head
- Doubly Linked List with head and tail
- Readings
- Homework
</details></li>

<li><details>
<summary>Trees</summary>

- Binary Trees
  Ordered Binary Trees
    - inorder
    - preorder
    - postorder
- Balanced Trees
- RBTree
- BTrees
- Tries
- Readings
- Homework
</details></li>

<li><details>
<summary>Hashing</summary>

- Hash functions
- Linear probing
- Linear chaining
- Quadratic probing
- Perfect hashing
- Use of hashing as 
- *Cryptographic hashing
- Readings
- Homework
</details></li>


<li><details>
<summary>Sorting and Shuffling</summary>

- bubble sort
- selection sort
- quicksort
- Lomuto vs. original partitioning for quicksort
- Knuth-modified quicksort
- Heapsort
- Mergesort
- Spreadsort
- Shuffling
  - Bad Shuffling
  - Unfair Shuffling
  - Fischer-Yates
- Readings
- Homework

</details></li>

<li><details>
<summary>Searching</summary>

- linear search
- binary search
- golden mean search
- Readings
- Homework
</details></li>

<li><details>
<summary>Strings</summary>

- naive string compare
- Boyer-Moore
- Finite State Machine (FSM)
- Longest Common Subsequence (LCS)
- Edit Distance
</details></li>

<li><details>
<summary>Numerical methods</summary>

- Properties of floating point
- inexact representation
- Roundoff error
- commutivity, associativity
- Root finding
- bisection
- Newton-Raphson
- Ridder's
- Numerical integration
- Basic methods: Euler, midpoint, trapezoidal
- Simpson's rule and why it is useless
- recursive trapezoidal and adaptive quadrature
- Gauss quadrature
- Romberg
</details></li>

<li><details>
<summary>Matrices</summary>

- Addition, subtraction
- Multiplication
- Lower bounds on matrix multiplication: Strassen, Coppersmith-Winograd
- Gauss-Jordan (Row reduction)
- Partial and full pivoting for numerical stability
- Least squares
- Gram-Schmidt
- Principal Component Analysis (PCA)
</details></li>

<li><details>
<summary>Graph theory</summary>

- Terminology of graph theory
- Representation of graphs (List, Matrix, CSR)
- primitives isAdjacent and allAdjacent
- DFS and BFS
- Djikstra/Bellman-Ford
- Floyd Warshall
- Prim
- Kruskal
- Travelling Salesman Problem (TSP)
</details></li>

<li><details>
<summary>number theoretic algorithms</summary>

- Greatest Common Denominator (GCD) and Lowest Common Multiple (LCM)
- Primality testing: Trial division
- Factoring
- Eratosthenes' Sieve
- probabilistic testing (Fermat, Miller Rabin)
- AKS (the concept of deterministic primality testing, not necessarily how to do it)
- RSA and asymmetric cryptography
</details></li>

<li><details>
<summary>Geometric Algorithms</summary>

- Space Trees (quadtree, octree)-
- Convex Hull
- Tessellation
- Interpolation of values
- Indexing to a regular grid
- Indexing to an irregular grid (effectively spatial hashing)
</details></li>

<li><details>
<summary>Compression</summary>
- Overview of Information theory
- Huffman
- Arithmetic encoding
- LZW (Lempel-Ziv-Welch)
- Burrows-Wheeler
- LZMA
- PPM
- Neural network prediction compressions (PAQ family)
- Kolmogorov complexity
- Lossy vs Lossless compression
- png, jpeg, jpeg2000, webp images 
</details></li>

<li><details>
<summary>Complexity theory</summary>
- P vs. NP 
- Turing machines
- Reducibility
- Satisfyability
- Knapsack problem
</details></li>

</ol>