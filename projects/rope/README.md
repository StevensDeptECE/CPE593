# Rope: a tree-based alternative to strings

Rope is a tree alternative to strings where a tree of text replaces the traditional string. See the description of chain for my alternative. This project explores implementing rope. If another team implements chain, you can compare results.

The first requirement of this project is to define the operations to be performed. The design must be capable of loading large files (100MB) very quickly, and performing operations on them. Obviously, primitives such as load, save, appending text, inserting and deleting are the fundamental primitives and a rough framework has been provided to give you a starting point. You will also define your own operations and take my basic design further as well as implementing the minimal set I have defined.

Here are some ideas for operations you should consider:

Comparing large files against each other. Performing diff between two large files, search and replace for text or patterns.

For creating an editor, you would need to be able to view a rectangle of text. The document could be wider than the windows, and is generally far taller than the window, and the window therefore represents a rectangular viewport on the document. Define an efficient algorithm to extract the rectangle to display the current text window, to incrementally move the window (scroll up, down, left, right, page up, page down, etc). Also if you were to write an editor, as the user types, they would need to modify the document based on changes to this rectangle.