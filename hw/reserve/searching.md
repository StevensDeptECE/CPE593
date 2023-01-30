# Searching

Your program should accept the name of a file on the command line. For example:

```bash
myprog search.dat
java myprog search.dat
```

Open the file, which is in the following format and use binary search to find the requested value in the list.

Output either the value found and how many iterations to find it or print "NOT FOUND" followed by the number of iterations before your code determined that it was not found.

Each case has three lines:
First line: the number of elements

Second line: a list of integers

Third, the number being searched for

Here is an example of the file format:

Cases: 3
10
1 3 6 10 15 20 21 22 25 26
4
20
1 3 6 10 15 20 21 22 25 26 27 28 30 31 32 40 41 45 50 51
60
20
1 3 6 10 15 20 21 22 25 26 27 28 30 31 32 40 41 45 50 51
27
The output should be:

NOT FOUND 3                     (or 4 might be ok)
NOT FOUND 5                    ( or 5 might be ok)
26 1

 It is ok if you get +1 iteration, that depends on your algorithm.  However, you cannot get 10 for the first case (that would be O(n))