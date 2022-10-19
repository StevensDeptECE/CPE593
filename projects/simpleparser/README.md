# Simple Parser

For simple scripting languages, very often each kind of statement can be recognized as a single regular expression. That can be recognized in O(n) time, where n is the length of the pattern, but if there are m different statements, then the complexity of figuring out which kind of statement is O(mn) where m are the number of different statement types. Typically, the code would look something like

```cpp
if (commentRegex.matches(line)) {
  // do whatever you do for comments
} else if ( assignmentRegex.matches(line)) {
  // do an assignment statement
} else ..

```

In a full programming language, you have nested structures, so it needs a grammar in addition which uses a stack, for example to check whether parentheses or curly braces match. In this project you are just looking at a simple one-level system that can do the match in O(n) time.

This project will require you to write your own regex engine, and to parse a textfile.

You may design your own language for the parsing, but the following example shows my proposal for a language that would allow me to define a regex parser to read in a configuration file.

comment = <!--[.*]-->
ident = ([a-zA-Z_][a-zA-Z0-9_]*)
assign = :ident:\s*=\s*
intassign = :assign:([0-9]+) -> parseInt()
fpassign = :assign:([0-9]+.[0-9]*) -> parsefp()
stringassign = :assign:"([^"])" -> parseString()
listassign = :assign:\[([^\]]\)] -> parseList()
statement = listassign|stringassign|fpassign|


