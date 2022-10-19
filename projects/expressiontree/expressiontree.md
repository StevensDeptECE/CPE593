#Expression Tree

This project explores creating a tree or DAG to represent expressions
on a computer and optimizing those expressions so that optimal code
can be generated. If we generated assembler code, this would be a core
part of an optimizing compiler, but in this case we are just
optimizing the tree as an exercise in tree manipulation.

The file [testexpressions.cc](testexpressions.cc) implements a number
of tests. Your job is to implement as many of those as possible and
analyze the complexity of the optimization. Some optimizations are
significantly more difficult and you will gain considerable difficulty
points if you can get those.

The expression tree must support constants (which can all be
considered double precision), variables (which can take on different
values and therefore are harder to optimize), binary operators such as
addition, subtraction, etc, unary operators such as negation, square
root, and functions such as sin, cos, tan, etc.

The first job is to read in the expression tree. For simplicity we will allow input to be in postfix (reverse polish) notation.

In general, an optimizer examines the expression tree and determines if there is an equivalent way to compute the answer that is faster. The following optimizations are to be coded. For all examples a and b are constants, and x and y are variables.
In the following list whenever you see parentheses that is an evaluated constant that is put into the tree.

1. a b + &#8594; (a+b)
1. a b - &#8594; (a-b)
1. a b * &#8594; (a*b)
1. a b / &#8594; (a/b)
1. x 0 + &#8594; x
1. x 1 * &#8594; x
1. x x - &#8594; 0
1. x x / &#8594; 1
1. x a * x b * + &#8594; x (a+b) *
1. x a * x b / + &#8594; x (a+1/b) *
1. x a * x b * - &#8594; x (a-b) *
1. x x * y y * + sqrt &#8594; x x * y y * + fastsqrt