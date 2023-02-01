# Adaptive Quadrature

Use adaptive quadrature to write a trapezoidal integration function that splits the interval in two, splits the error in two, and tries to recursively increase the number of slices only for those parts of the function where the error remains too big.  To do so, you will have to compute both the area and the estimated error in a lower level function.

If the error for the entire function is epsilon, then each half should have an error maximum of epsilon/2. Thus if the function is very small on the left side, there is no reason to keep refining that side. This can dramatically reduce work as well as unnecessary roundoff error.

Example function:

$f(x) = 1/(x-3)^4$

We know there is an analytical solution, giving us something to compare to:

$\int_0^4 f(x) dx = \frac{-1}{3(x-3)^3}|_0^4 = \frac{-1}{3}$

The function should look the same as trapezoidal from the outside:

```cpp
double adaptive(FuncOneVar f, double a, double b, double eps);
```