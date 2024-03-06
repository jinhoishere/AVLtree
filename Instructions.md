## Table of Contents:
* [Learning Objectives](#learning-objectives)
* [Overview](#overview)
* [Program Operation](#program-operation)
* [Example](#example-of-program-execution)
* [Grading](#turn-in-and-grading)

---

## _Learning Objectives_

- Demonstrate effective use of memory management techniques in C++
- Implement a data structure to meet given specifications
- Design, implement, and use an AVL tree data structure
- Analyze operations for time complexity

## _Overview_

  Your task for this assignment is to implement an AVL tree that serves as a map data type (sometimes also called a dictionary. A map allows you to store and retrieve key/value pairs. For this project, the key will be an integer and the value will be a string.

## _The AVLTree Class_

The map will be implemented as an AVL tree. For this project, you must write your own AVL tree - not using code from outside sources. Your AVL tree should remain balanced by implementing single and double rotations when inserting new data. Your tree must support the following operations: 

- `bool AVLTree::insert(int key, string value)` – Insert a new key/value pair into the tree. For this assignment the duplicate keys are not allowed. This function should return **true** if the key/value pair is successfully inserted into the map, and **false** if the pair could not be inserted (for example, due to a duplicate key already found in the map). The time complexity for insert should be O(log2 n).

- `int AVLTree::getHeight()` – return the height of the AVL tree. The time complexity for getHeight should be O(1).

- `int AVLTree::getSize()` – return the total number of nodes (key/value pairs) in the AVL tree. The time complexity for getSize should be O(1).

- `friend ostream& operator<<(ostream& os, const AVLTree& me)` ‐ print the tree using the << operator. You should overload the << operator to print the AVL tree “sideways” using indentation to show the structure of the tree. For example, consider the following AVL tree (each node contains a key, value pair):

![AVLTree](https://github.com/WSU-CS-3100/Project4/assets/108754033/2aec7ac5-0fb0-414b-9ca8-a34a551c078b)

This tree would be printed as follows:

![Screenshot 2024-03-06 at 17-30-53 CS 3100 Project #4](https://github.com/WSU-CS-3100/Project4/assets/108754033/dcbee2e6-433c-47ff-b39b-10ea8ba8dca7)

_(Note: If you turn your head sideways, you can see how this represents the tree.)
(Also note: This style of printout can be directly implemented as a right-child-first inorder traversal of the tree.)_

- `bool AVLTree::find(int key, string& value)` – if the given key is found in the AVL tree, this function should return true and place the corresponding value in value. Otherwise this function should return false (and the value in value can be anything). The time complexity for find should be O(log2 n).

- `vector<string> AVLTree::findRange(int lowkey, int highkey)` – this function should return a C++ vector of strings containing all of the values in the tree with keys ≥ lowkey and ≤ highkey. For each key found in the given range, there will be one value in the vector. If no matching key/value pairs are found, the function should return an empty vector.

**Example:** Suppose the call `resultVector = myTree.findRange(30, 47)` were called on the tree pictured above. The findRange function would then return a vector containing the strings: {"Thirty", "Fourty", "Forty five"}.

## _Turn in and Grading_

- The AVLTree class should use a seperate AVLTree.h and AVLTree.cpp file.
- Please zip your entire project directory into a single file called project4.zip and upload to the dropbox in Pilot.

