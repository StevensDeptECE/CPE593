#Edit Distance

Write a program that accepts two parameters on the command line which are the names of two files to be read in.

```bash
EditDist a.txt b.txt

java EditDist a.txt b.txt
```

Return the edit distance between the contents of the two files.

Edit Distance is a similar algorithm to LCS, so this assignment should be relatively easy if you have already done LCS.  Same rules apply, only this time, what you are measuring is how many edits it takes to convert file a to file b.

For example, for the text:

ABCD              ABCDE

to turn the first file into the second, you must insert 1 letter, and the value to print is 1.

ABCD             ABDE

The second example requires you to delete the letter C and add the E for a value of 2.

The third case is replacement

ABCD          ABXD

has a cost of 1 because instead of deleting the C and inserting the X, you can replace the C with X in a single step.



 

We can pick any two filenames we like, which will be read from the current directory.  Do not append any path to the filename, or it will not work on our computer and you will lose points.