# Dictionary Compression

Read in the provided set of n books of an average length of m words each. Strip out all punctuation.
Deal with upper/lowercase issues, otherwise many words will appear in both upper and lowercase versions just because they are at the beginning of sentences.
First, create a dictionary of all the words in all the books. The dictionary should be capable of counting how many times the word has been seen, and in how many different files the word has been seen.

Choose the top k words, for example, the most popular 500 words. This will be general short words like and, or, but, if, the, etc. Each word must map to a unique integer id from 1 to k. For example, if the word "the" is the most common word, and "and" is 2nd most common then the --> 1, and --> 2.

Go back and construct a histogram count of the frequency of all sequences of words with the following rules:

1. Sequence continues for as long as words are in the k most used list with at most 1 word not on the list.
1. Replace the word not in the list with the special token 0.
1. Create a dictionary of all sequences of words.

For example, given the following text

It was the best of times, it was the worst of times.

First strip off the punctuation and remove case:

it was the best of times it was the worst of times

Then, add all words into the dictionary. Suppose all short words "it", "was", "the", "of" are in the top 500 but "best", "times" and "worst" are not. Then you will count:

it was the 0 of
0 of
of 0 it was the
0 it was the
it was the 0 of
of 0

Of course, with 500 of the top words, there are going to be many different sequences. It is probably too inefficient to use an array of 500 to implement the trie. There will probably not be very many different sequences. There probably are:

it was the best of times ...
it was the last decade ...
it was the end of an era ...
it was the beginning of a whole new ...

would turn into
it was the 0 of
it was the 0
it was the 0 of an
it was the 0 of a

Every word turns into a number, so really the above should be written something like:

5 19 1 0 98
5 19 1 0
5 19 1 0 98 153
5 19 1 0 98 3

Create a data structure that stores these, and then assign each sequence a unique code for all the sequences with frequency > f. Obviously there will be sequences of words that only appear once in all the books. That isn't worth storing in the dictionary. I don't know what the threshhold should be, so you can start by setting f = 10. (Make it a parameter of your program that you can set.)

In the end your program should be able to write out the dictionary of the individual words (the top k most used words) and the dictionary of all sequences with frequency f to disk. A second program should be able to load that back in. So once you read 1000 books, process them all, calculate the dictionary, you should be able to load the result very quickly.
