# Chain Project
Chain is an efficient tree structure to represent extremely large files.

The "string" is a common array-based object where letters are stored
sequentially in memory. The problem with strings is that when they get
large, inserting in the middle gets increasingly expensive.

Rope was a tree-based approach described in 1995 by Boehm and Russ.
While it is more efficient for large files, using a tree to represent a complete file down to the level of individual letters is not ideal.

Chain is a hybrid concept by Dov Kruger, where the leaves of the tree are lines,
and each individual line is a conventional string. This uses fewer
nodes than representing each individual letter as a tree node. In
order to improve the efficiency, the strings are represented as
offsets into a single pool of memory rather than individual pointers.

There are advantages and disadvantages to the single pool of
memory. On the one hand, once memory is exceeded growing is expensive
since the pool will have to be reallocated and copied. On the other
hand, each pointer is only 32-bits instead of 64, and allocating
individual chunks of memory is faster than using new because there is
no overhead for allocating individual chunks. For example malloc
typically uses a 64-bit number to store the size just before the block
allocated, meaning that an addition 8 bytes is used for every memory
allocation, which also means it has to be written each time. Additionally, disk I/O using the contiguous block of memory is extremely fast because it can be done in a single read or write.

Since growth is so expensive, the idea is to allocate a lot more
memory than needed, knowing that alllocating virtual memory is not
expensive unless you actually use it.

See the files [chain.hh](chain.hh) and [testchain.cc] for sample
specifications of this class.

Write the implementation of chain, and write a quick comparison using strings demonstrating how much faster the tree-based approach is at large sizes, n=100kB, 1MB, 10MB, and 100MB. YOu should be able to load in a file, manipulate it (insert characters, insert lines of text, remove lines of text, etc.) and save it out to disk. Implement a quick string-based version as a basis of comparison. We would expect a string implementation to be $O(mn)$ for m insertions in the middle of n bytes, whereas your tree implementation should be $O(m \log k)$.

