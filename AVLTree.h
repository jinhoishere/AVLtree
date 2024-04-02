// CS 3100 Project 4 by Jinho Nam
// There must be "AVLTree.cpp" file in the same directory

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class AVLTree {
    private:
        class Node {
            public: 
                // Fields
                int key;
                string value;
                int height;
                Node* left;
                Node* right;

                // Default Constructor
                Node() {
                    key = 0;                    
                    value = "";
                    height = 0;
                    left = nullptr;
                    right = nullptr;
                };

                // Parameterized Constructor
                Node(int newKey, string newValue) {
                    key = newKey;
                    value = newValue; 
                    height = 0;
                    left = nullptr;
                    right = nullptr;
                }

                // Update height of the (current) node
                int updateHeight(Node*&);

                // Calculate balance of the (current) node
                int getBalance(Node*&);

                // Return the greater one between two integers
                int max(int, int);

        };

        // Member data: the data item(s) that each AVLTree object has.
        Node* root; // root of the tree
        int size; // the number of nodes in the tree

        // Help deep-copying a tree
        Node* copyHelper(const Node*);

        // Help inserting a new key/value pair into the tree
        bool insertHelper(int, string, Node*&);

        // Help finding a node with the matching key and 
        // changing the value within the node.
        bool findHelper(int, string&, Node*&);

        // Help finding values within the range of keys
        void findRangeHelper(Node*&, vector<string>&, int, int);

    public:
        // Default Constructor
        AVLTree();

        // Copy Constructor (t = tree to be copied)
        AVLTree(const AVLTree& t);

        // Destructor
        ~AVLTree();

        // Deep Copy
        AVLTree& operator=(const AVLTree&);

        // Delete the node and its sub-tree
        void deleteSubTree(Node*);

        // Insert (int)key and (string)value with in the tree
        bool insert(int, string);

        // Find (int)key and (string&)value in the tree
        bool find(int, string&);
        
        // Return the max height of the node in the tree
        int getHeight();

        // Return the number of nodes in the tree
        int getSize();

        // Single left rotation (Node*& problem)
        void singleLeftRotation(Node*&);

        // Single right rotation (Node*& problem)
        void singleRightRotation(Node*&);

        // Double left rotation (Node*& problem)
        void doubleLeftRotation(Node*&);

        // Double right rotation (Node*& problem)
        void doubleRightRotation(Node*&);

        // Return all the value(s) within the key range
        vector<string> findRange(int, int);
        
        // Reverse inorder traversal for printing
        void inorder(ostream&, Node*, int) const;

        // Overload << operator
        friend ostream& operator<<(ostream& os, const AVLTree& me);

};