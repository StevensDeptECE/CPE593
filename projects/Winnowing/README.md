# Winnowing

The winnowing algorithm is used to measure the similarity of text files when people are consciously trying to obfuscate, for example when students are trying to copy data structures homework and change a variable or two, and rearrange functions to not get caught. Winnowing is published and the article is in the ref directory of the course repo.

Stanford's MOSS service has been used to help countless teachers find plagiarizing students, but the source code is not available.

Implement your own implementation of MOSS and demonstrate the cost of comparing n homework assignments. Currently MOSS can only handle assignments in one language, so for this class, that means it cannot compare someone in C++ copying from someone in Java. To be fair, it's not literally copying since there is work in translation, but an interesting extension to this project would be doing winnowing not on the source code, but on the underlying structure of the code. That is unfortunately, very hard to do in C++ since you would effectively have to write a compiler. If you wish to implement a project with this idea you could demonstrate using a toy language of your own invention, or you could use the object code since all languages will compile to machine language.

Obviously the easy way is just to compare source code and demonstrate winnowing. Any alternative should be proposed to me, and I will determine if your idea is acceptable.
