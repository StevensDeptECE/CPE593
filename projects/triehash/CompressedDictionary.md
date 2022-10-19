# Compressed Trie of Hashmaps Dictionary Project
For this project you will be using a dictionary of 213k words, and a
bigger one of 466k words to test.


The goal is to store the dictionary compactly and load it as fast as
possible (and of course to be able to look up words efficiently once
loaded). While it should be possible to update the dictionary, it is
of seconday importance how fast that is, as generally the dictionary
will not change.

This project implements a tree of hashmaps. In order to compress the
dictionary, we rely on the fact that the words are stored in
alphabetic order. Accordingly, this means that we should not need to
store the first k letters of each word, as generally that is the same
as the first k of the last word. The individual letters should be
stored using arithmetic encoding. We will consider only single case,
and words will only be letters so there are 26 separate symbols to
represent for English. In order to represent two categories of words,
two end tokens will be defined END1 and END2.

For example, the word "hello" would be represented as:

h e l l o END1

or

h e l l o END2

depending on whether the word is to be put into category 1 or 2.

To encode the words using arithmetic encoding, considering that there
are 28 unique symbols including the two end symbols, use base 28,
encoding each letter as a number from 0 to 25, END1=26 and END2=27.

The resulting equation would be ((8 * 28 + 5) * 28 + 12) * 28 ...
ending in 26 for the END1 token.

Read in the dictionary and count the number of elements that start
with the letter a. There will be many. Therefore, break down into
words starting with aa, ab, ac, etc. Stop breaking down when the
number of words is less than k. While this should be programmable,
let's consider the number to be 64. This should mean that you identify
all words starting with a given prefix, create a hashmap big enough to fit it in the table, then move to the next prefix, build another hashmap.
