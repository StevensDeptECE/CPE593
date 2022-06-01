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

Analyzing complexity
* Big O, &Omega;, theta
* Analyzing loops to determine complexity
* Analyzing loops with if statements to determine complexity (&Omega;)
* Understanding omega (surprising how many people miss this sometimes even if they sometimes get it right)
* Analyzing recursion
* Dynamic programming

lists
* dynamic array
* linked list (head, head/tail, single, double)
* stacks
* queue

number theoretic algorithms
* Greatest Common Denominator (GCD) and Lowest Common Multiple (LCM)
* Primality testing: Trial division
* Factoring
* Eratosthenes' Sieve
* probabilistic testing (Fermat, Miller Rabin)
* AKS (the concept of deterministic primality testing, not necessarily how to do it)
* RSA and asymmetric cryptography

Sorting
* bubble sort
* selection sort
* quicksort
* Lomuto vs. original partitioning for quicksort
* Knuth-modified quicksort
* Heapsort
* Mergesort
* Spreadsort
* Fischer-Yates (shuffling)

Searching
* linear search
* binary search
* golden mean search

Trees
* Binary Trees
* Expression Trees
* inorder, preorder, postorder traversal
* Ordered binary Trees
* RB Trees
* Tries

Hashing
* Hash functions
* Linear probing
* Linear chaining
* Quadratic probing
* Perfect hashing
* Use of hashing as 
* Cryptographic hashing

Strings
* naive string compare
* Boyer-Moore
* Finite State Machine (FSM)
* Longest Common Subsequence (LCS)
* Edit Distance

Numerical methods
* Properties of floating point
** inexact representation
** Roundoff error
** commutivity, associativity
* Root finding
** bisection
** Newton-Raphson
** Ridder's
* Numerical integration
** Basic methods: Euler, midpoint, trapezoidal
** Simpson's rule and why it is useless
** recursive trapezoidal and adaptive quadrature
** Gauss quadrature
** Romberg

Matrices
* Addition, subtraction
* Multiplication
* Lower bounds on matrix multiplication: Strassen, Coppersmith-Winograd
* Gauss-Jordan (Row reduction)
* Partial and full pivoting for numerical stability
* Least squares
* Gram-Schmidt
* Principal Component Analysis (PCA)

Graph theory
* Terminology of graph theory
* Representation of graphs (List, Matrix, CSR)
* primitives isAdjacent and allAdjacent
* DFS and BFS
* Djikstra/Bellman-Ford
* Floyd Warshall
* Prim
* Kruskal
* Travelling Salesman Problem (TSP)

Geometric Algorithms
* Space Trees (quadtree, octree)
* Convex Hull
* Tessellation
* Interpolation of values
* Indexing to a regular grid
* Indexing to an irregular grid (effectively spatial hashing)

Compression
* Overview of Information theory
* Huffman
* Arithmetic encoding
* LZW (Lempel-Ziv-Welch)
* Burrows-Wheeler
* LZMA
* PPM
* Neural network prediction compressions (PAQ family)
* Kolmogorov complexity
* Lossy vs Lossless compression
* png, jpeg, jpeg2000, webp images 


Complexity theory
* P vs. NP 
* Turing machines
* Reducibility
* Satisfyability
* Knapsack problem
 

