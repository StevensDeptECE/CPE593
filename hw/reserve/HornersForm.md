# Horners Form

Write a program to read two lists of coefficients. Create a polynomial object for each one, and evaluate using Horner's form.  For example:

4

1  3  5  -1  2

3

1  2 -3  2

Represents the two polynomials:

1 + 3x + 5x^2 - x^3 + 2x^4

and

1 + 2x - 3x^2 + 2x^3

then read in each line of the remainder of the file, evaluating the two polynomials. For example, given the input:
1.0

the outputs are:

10.0

2.0

