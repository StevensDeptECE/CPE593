# Removing Common Headers and Footers from Project Gutenberg Books

Project Gutenberg is a collection of free books in the public domain transcribed into common formats such as .txt and .epub.
Each file contains a header at the beginning and a license at the end. Particularly the license at the end can be quite large.
There are probably multiple versions of the header and license over time, so they are not quite the same.
The header contains information that may be different in each book, such as the names of the people who were responsible for the conversion.

Your job is to remove the header and the license, keep just one of each (there are probably multiple versions that evolved over time), and create a program capable of recreating the original file by encoding the custom information of the header. Analyze the complexity of the operation on n files, each of which is an average of m bytes long.

Your program will not recreate the "original" file if you only have one version of the license. The point is, I don't care, I just want a single copy of a single version of the license which can be updated if desired. The point here is to figure out what is license and remove it, figure out what is the header, keep only the information that is different (like the names of the people) and remove that as well.

The program should display the total size of the resulting files written to disk, the total size of the originals, and amount by which the data has shrunk, and the percentage.

