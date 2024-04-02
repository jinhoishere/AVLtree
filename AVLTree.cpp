// CS 3100 Project 4 by Jinho Nam
// There must be "AVLTree.h" file in the same directory

#include "AVLTree.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Default Constructor
AVLTree::AVLTree() {
    root = nullptr;
    size = 0;
}

// Copy Constructor
AVLTree::AVLTree(const AVLTree& t) {
    // Set fields to default before copying
    root = nullptr;
    size = 0;

    // Copy nodes using copyHelper()
    Node* copiedRoot = t.root;
    root = copyHelper(copiedRoot);    
}

// Destructor
AVLTree::~AVLTree() {
    //  return; // a line of code for memory leak test
    deleteSubTree(root);
}

// -------------------------------------------------------------
// AVLTree::opearator=: create a new tree that is exactly
//                       same as the parameter one.
// Returns: *this (AVLTree&)
// Parameters:
//       t (const AVLTree&)
// -------------------------------------------------------------
AVLTree& AVLTree::operator=(const AVLTree& t) {
    // Clear "this" tree first to make it default status
    this -> deleteSubTree(root);
    root = nullptr;

    // Copy tree 't' to the current tree
    Node* copiedNode = t.root;
    this -> copyHelper(copiedNode);

    return *this;
}

// -------------------------------------------------------------
// AVLTree::copyHelper: a method to help copying a tree
//                      by coping nodes one by one.
// Returns: newNode (Node*)
// Parameters:
//       current (const Node*)
// -------------------------------------------------------------
AVLTree::Node* AVLTree::copyHelper(const Node* current) {
    if (current == nullptr) {
        return nullptr;
    }
    else {
        // Copy nodes one by one recursively
        Node* newNode = new Node(current -> key, current -> value);
        (newNode -> height) = (current -> height);
        (this -> size) += 1;
        (newNode -> left) = copyHelper(current -> left);
        (newNode -> right) = copyHelper(current -> right);

        return newNode;
    }   
}

// -------------------------------------------------------------
// AVLTree::deleteSubTree: a method to help deleting a subtree of the node
// 
// Returns: -
// Parameters:
//       current (Node*)
// -------------------------------------------------------------
void AVLTree::deleteSubTree(Node* current) {
    if (current == nullptr) {
        return;
    }
    deleteSubTree(current -> left);
    deleteSubTree(current -> right);
    delete current;
    size -= 1;
}

// -------------------------------------------------------------
// AVLTree::insert: pass (int)key, (string)value, (Node*)root to the
//                  insertHelper() method
// 
// Returns: insertHelper(key, value, root)
// Parameters:
//       key (int)
//       value (string)
// -------------------------------------------------------------
bool AVLTree::insert(int key, string value) {
    return insertHelper(key, value, root);
}

// -------------------------------------------------------------
// AVLTree::insertHelper: insert (int)key, (string)value to the (Node*&) current
// 
// Returns: returnValue = true
//          (a new node with (int)key and (string)value.)
// Parameters:
//       key (int)
//       value (string)
// -------------------------------------------------------------
bool AVLTree::insertHelper(int key, string value, AVLTree::Node*& current) {
    // Local variables
    bool returnValue;
    int currentBalance = 0;
    int leftBalance = 0;
    int rightBalance = 0;

    // Insert a new node
    if (current == nullptr) {
        current = new Node(key, value);
        size += 1;
        returnValue = true;
    }
    else if (key == (current -> key)) {
        // cout << "**You can't insert the same key that is already in the tree, key: " << key << endl;
        returnValue = false;
    }
    else if (key < (current -> key)) {
        returnValue = insertHelper(key, value, (current -> left));
    }
    else {
        returnValue = insertHelper(key, value, (current -> right));
    }
    
    // Calculate the height of the current node
    (current -> height) = current -> updateHeight(current);

    // Check the balance of the current node
    currentBalance = current -> getBalance(current);

    // Check the balances of the current node's left and right balance
    leftBalance = current -> getBalance(current -> left);
    rightBalance = current -> getBalance(current -> right);
    

    // If necessary, do rotations
    if ((currentBalance >= 2) || (currentBalance <= -2)) {
        // cout << "** The node " << (current -> key) << " is the deepest unbalanced node." << endl;

        // single left rotation
        if ((currentBalance < 0) && (rightBalance <= 0)) {
            this -> singleLeftRotation(current);
        }
        // single right rotation
        else if ((currentBalance > 0) && (leftBalance >= 0)) {
            this -> singleRightRotation(current);
        }
        // double left rotation
        else if ((currentBalance < 0) && (rightBalance > 0)) {
            this -> doubleLeftRotation(current);
        }
        // double right rtoation
        else if ((currentBalance > 0) && (leftBalance < 0)) {
            this -> doubleRightRotation(current);
        }

        // Recalculate the height after rotation
        root -> updateHeight(root);
    }

    return returnValue;
}

// -------------------------------------------------------------
// AVLTree::find: pass (int)key and (string)value to the
//                  findHelper() method.
// Returns: findHelper(key, value, root)
// Parameters:
//       key (int)
//       value (string&)
// -------------------------------------------------------------
bool AVLTree::find(int key, string& value) {
    return findHelper(key, value, root);
}

// -------------------------------------------------------------
// AVLTree::findHelper: Find a node with (int)key and (string&)value
//                  
// Returns: true
//          (value = (current -> value))
// Parameters:
//       key (int)
//       value (string&)
//       current (Node*&)
// -------------------------------------------------------------
bool AVLTree::findHelper(int key, string& value, AVLTree::Node*& current) {
    if (current == nullptr) {
        return false;
    }
    else if ((key == (current -> key))) {
        value = (current -> value);
        return true;
    }
    else if (key < (current -> key)) {
        return findHelper(key, value, (current -> left));
    }
    else {
        return findHelper(key, value, (current -> right));
    }
}

// -------------------------------------------------------------
// AVLTree::getHeight: Return the max height of the tree
//                     (= Height of the root node)
// Returns: Height of the root node (int)
// Parameters: -
// -------------------------------------------------------------
int AVLTree::getHeight() {
    if (this -> root) {
        return this -> root -> height;
    }
    else {
        return 0;
    }
}

// -------------------------------------------------------------
// AVLTree::updateHeight: Update height of the tree recursively
// 
// Returns: 1 + max(leftHeight, rightHeight)
// Parameters: 
//          current (Node*&)
// -------------------------------------------------------------
int AVLTree::Node::updateHeight(AVLTree::Node*& current) {
    // Local variables: default heights are -1
    int leftHeight = -1;
    int rightHeight = -1;
    if (current == nullptr) {
        return -1;
    }
    else {
        // Call method recursively to move down along the tree
        leftHeight = updateHeight(current -> left);
        rightHeight = updateHeight(current -> right);

        // Set height for the node
        (current -> height) = 1 + max(leftHeight, rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
}

// -------------------------------------------------------------
// AVLTree::getSize: Return # of nodes in the tree
// -------------------------------------------------------------
int AVLTree::getSize() {
    return this -> size;
}

// -------------------------------------------------------------
// Node::max: Return greater one between t1 and t2
// -------------------------------------------------------------
int AVLTree::Node::max(int i1, int i2) {
    if (i1 >= i2) {
        return i1;
    }
    else {
        return i2;
    }
}

// -------------------------------------------------------------
// Node::getBalance: Return the balance of the node
// 
// Returns: leftHeight - rightHeight
// Parameters: 
//          current (Node*&)
// -------------------------------------------------------------
int AVLTree::Node::getBalance(Node*& current) {
    // Local variables: default heights are -1
    int leftHeight = -1;
    int rightHeight = -1;

    // If the current node is not null
    if (current) {
        // Check height of the left-child node
        if ((current -> left) != nullptr) {
            leftHeight = (current -> left -> height);
        }
        // Check height of the right-child node
        if ((current -> right) != nullptr) {
            rightHeight = (current -> right -> height);
        }
    }
    
    return leftHeight - rightHeight;
}

// Do single left rotation on the problem node
void AVLTree::singleLeftRotation(Node*& problem) {
    Node* hook = problem -> right;
    Node* tmp = (hook -> left);
    (hook -> left) = problem;
    (problem -> right) = tmp;
    problem = hook;
}

// Do single right rotation on the problem node
void AVLTree::singleRightRotation(Node*& problem) {
    Node* hook = (problem -> left);
    Node* tmp = (hook -> right);
    (hook -> right) = problem;
    (problem -> left) = tmp;
    problem = hook;
}

// Do double left rotation on the hook (problem -> right) node
void AVLTree::doubleLeftRotation(Node*& problem) {
    singleRightRotation(problem -> right);
    singleLeftRotation(problem);
}

// Do double right rotation on the hook (problem -> left) node
void AVLTree::doubleRightRotation(Node*& problem) {
    singleLeftRotation(problem -> left);
    singleRightRotation(problem);
}

// -------------------------------------------------------------
// AVLTree::findRange: return a vector with the value of nodes that contains
//                     key from "lowKey" and "highKey"
// Returns: results (vector<string>)
// Parameters: 
//          lowKey (int)
//          highKey (int)
// -------------------------------------------------------------
vector<string> AVLTree::findRange(int lowKey, int highKey) {
    vector<string> results;
    // If the tree is empty, return null vector
    if ((this -> root) == nullptr) {
        return results;
    }
    // Else the tree is not empty, run findRangeHelper
    else {
        findRangeHelper(root, results, lowKey, highKey);
    }
    return results;
}

// -------------------------------------------------------------
// AVLTree::findRangeHelper: put values of the nodes in the vector<string> results
//                     
// Returns: -
// Parameters: 
//          current (Node*&)
//          results (vector<string>&)
//          lowKey (int)
//          highKey (int)
// -------------------------------------------------------------
void AVLTree::findRangeHelper(Node*& current, vector<string>& results, int lowKey, int highKey) {
    // If the current node is null
    if (!current) {
        return;
    }
    // Else the current node is not null
    else {
        findRangeHelper((current -> left), results, lowKey, highKey);
        // If the current node is out of the range
        if ( ((current -> key) >= lowKey) && ((current -> key) <= highKey) ) {
            results.push_back(current -> value);
        }
        // Else the current is within the range
        findRangeHelper((current -> right), results, lowKey, highKey);
    }
}

// Reverse inorder traversal for printing the tree
void AVLTree::inorder(ostream& os, Node* current, int depth) const {
    if (current == nullptr) {
        return;
    }
    else {
        this -> inorder(os, (current -> right), (depth + 1));
        // Print depth*2 spaces
        for (int i = 0; i < depth; i++) {
            os << "     ";
        }
        // Print value of the node
        os << "(" << (current -> key) << ", "<< (current -> value) << ")" << endl;
        this -> inorder(os, (current -> left), (depth + 1));
    }
}

// Print the tree
ostream& operator<<(ostream& os, const AVLTree& me) {
    me.inorder(os, me.root, 0);
    return os;
}