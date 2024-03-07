# Project4

- The AVLTree class should use a seperate AVLTree.h and AVLTree.cpp file.
- Please zip your entire project directory into a single file called project4.zip and upload to the dropbox in Pilot.

This project is worth 50 points, distributed as follows:
| Task                                                                                                                          | Points |
| ----------------------------------------------------------------------------------------------------------------------------- | ------ | 
|`AVLTree::insert` stores key/value pairs in the correct locations in the AVLTree, and correctly rejects duplicate keys| 	3|
|`AVLTree::getHeight()` correctly returns the height of the tree 	|3|
|`AVLTree::getSize()` correctly returns the number of key/value pairs in the tree 	|3|
|The tree maintains correct balance, regardless of the order in which keys are inserted 	|10|
|`operator<<` prints the tree in a neat and readable manner, using indentation or some other appropriate mechanism to clearly show the structure of the tree 	|4|
|`AVLTree::find` correctly finds and returns key/value pairs in the tree in Θ(log n) time, and returns false when no matching key is found 	|4|
|`AVLTree::findRange` correctly returns a C++ vector of strings matching keys in the specified range 	|6|
|`AVLTree::operator=` correctly creates an independent copy of an AVL tree 	|4|
|Copy constructor correctly creates an independent copy of an AVL tree 	|4|
|Code has no memory leaks 	|4|
|Code is well organized, well documented, and properly formatted. Variable names are clear, and readable. Your AVLTree class is declared and implemented in separate (.cpp and .h) files. 	|5|
