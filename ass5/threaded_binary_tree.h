#ifndef THREADEDTREE_H
#define THREADEDTREE_H
#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    bool leftThread, rightThread;
};

class ThreadedBinarySearchTree {
    // Outputs an entire threadedTree
    friend class Node;
    // Overloaded ostream operator to output a TBST
    friend ostream& operator<<(ostream& out, const ThreadedBinarySearchTree& tree);

public:
    // Root of the TBST
    Node* root;
    
    // Constructor
    ThreadedBinarySearchTree();
    // Single Parameter constructor
    explicit ThreadedBinarySearchTree(const int n);
    // Copy Constructor
    ThreadedBinarySearchTree(const ThreadedBinarySearchTree &other);
    // Destructor
    ~ThreadedBinarySearchTree();
    // Checks if the TBST contains a specific value
    bool contains(const int key) const;
    // Clears the TBST
    void makeEmpty();
    // Inserts a value in the TBST/
    void insert(const int key);
    // Searches for a value in TBST
    Node* search(const int key) const;
    // Removes a value from TBST
    void remove(const int key);
    // Returns highest value from TBST
    int getHighest() const;
};

#endif
