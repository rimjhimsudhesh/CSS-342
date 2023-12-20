/*
 * C++ Program to Implement Threaded Binary Tree
 * 
 * Rimjhim Sudhesh and Michael Schwartz
 * 🐇🐇🐇
 * 🦒🦒🦒
 */
#include <iostream>
#include "threaded_binary_tree.h"
#define MAX_VALUE 65535;
using namespace std;

  /*
    Overloaded ostream operator to print out a TBST

    @param out as the ostream that the tree will be returned to
    @param tree as the tree being printed
    @return ostream to be printed
  */
  ostream& operator<<(ostream& out, const ThreadedBinarySearchTree& tree) {
    Node* temp = tree.root->left;
    while(temp != tree.root) {
      out << temp->key << " ";
      if(temp->rightThread) {
        temp = temp->right;
      } else {
        temp = temp->right;
        while(!temp->leftThread) {
          temp = temp->left;
        }
      }
    }
    return out;
  }


  /* 
    No Parameter constructor for ThreadeBinarySearchTree
  */
  ThreadedBinarySearchTree::ThreadedBinarySearchTree() {
    root = new Node();
    root->right = root->left = root;
    root->leftThread = true;
    root->key = MAX_VALUE;
  }

  /*
    One parameter constructor for ThreadedBinarySearchTree

    @param n as the number of nodes being added to the tree
  */
  ThreadedBinarySearchTree::ThreadedBinarySearchTree(const int n) {
    root = new Node();
    root->right = root->left = root;
    root->leftThread = true;
    root->key = MAX_VALUE;
    for(int i = 1; i <= n; i++) {
      insert(i);
    }
  }
  
  /*
    Copy constructor for TBST

    @param other as the TBST being copied
  */
  ThreadedBinarySearchTree::ThreadedBinarySearchTree(const ThreadedBinarySearchTree &other){
    root = new Node();
    root->right = root->left = root;
    root->leftThread = true;
    root->key = MAX_VALUE;
    Node *temp = other.root->left;
    while(temp != other.root) {
      insert(temp->key);
      if(temp->rightThread) {
        temp = temp->right;
      } else {
        temp = temp->right;
        while(!temp->leftThread) {
          temp = temp->left;
        }
      }
    }
  }

  /*
    Destructor for the ThreadedBinarySearchTree class
  */
  ThreadedBinarySearchTree::~ThreadedBinarySearchTree() {
    makeEmpty();
    delete root;
    //cout << "tree destroyed" << endl;
  }

  /* 
    Makes the entire tree empty
  */
  void ThreadedBinarySearchTree::makeEmpty() {
    Node* cur = root->left;
    while(cur != root) {
      if(cur->rightThread) {
        Node* temp = cur->right;
        delete(cur);
        cur = temp;
      } else {
        Node* temp = cur->right;
        while(!temp->leftThread) {
          temp = temp->left;
        }
        Node* del = cur;
        cur = temp;
        delete(del);
      }
    }
  }

  /* 
    Inserts a new node with value key in the tree

    @param key as the value being inserted
   */
  void ThreadedBinarySearchTree::insert(const int key) {
    Node *point = root;
    for (;;) {
      if (point->key < key) {
        if (point->rightThread)
          break;
        point = point->right;
      } else if (point->key > key) {
        if (point->leftThread)
          break;
        point = point->left;
      } else {
        /* redundant key */
        return;
      }
    }
    Node *tmp = new Node();
    tmp->key = key;
    tmp->rightThread = tmp->leftThread = true;
    if (point->key < key) {
      /* insert to right side */
      tmp->right = point->right;
      tmp->left = point;
      point->right = tmp;
      point->rightThread = false;
    } else {
      tmp->right = point;
      tmp->left = point->left;
      point->left = tmp;
      point->leftThread = false;
    }
  }

  /* 
    Searches for a node with a given value in the TBST

    @param key as the value being searched for
    @return node pointer to the node with value key
    */
  Node* ThreadedBinarySearchTree::search(const int key) const {
    Node *tmp = root->left;
    for (;;) {
      if (tmp->key < key) {
        if (tmp->rightThread)
          return nullptr;
        tmp = tmp->right;
      } else if (tmp->key > key) {
        if (tmp->leftThread)
          return nullptr;
        tmp = tmp->left;
      } else {
        return tmp;
      }
    }
  }

  /*
    Checks the TBST and determines if the tree contains a node with value key

    @param key as the value being looked for
    @return true if TBST contains key, false otherwise
  */
  bool ThreadedBinarySearchTree::contains(const int key) const{
    return (search(key) != nullptr);
  }

  /*
    Returns the highest node value in the TBST

    @return int of the highest node value
  */
  int ThreadedBinarySearchTree::getHighest() const {
    Node* cur = root;
    if(root == nullptr){
      return -1;
    }
    while(cur->rightThread) {
      cur = cur->right;
    }
    return cur->key;
  }

  /*
    Removes a node with value key from the tree

    @param key as the node being deleted
  */
  void ThreadedBinarySearchTree::remove(const int key) {
    Node *point = root;
    Node *dest = root->left;
    for (;;) {
      if (dest->key < key) {
        /* not found */
        if (dest->rightThread)
          return;
        point = dest;
        dest = dest->right;
      } else if (dest->key > key) {
        /* not found */
        if (dest->leftThread)
          return;
        point = dest;
        dest = dest->left;
      } else {
        /* found */
        break;
      }
    }
    Node *target = dest;
    if (!dest->rightThread && !dest->leftThread) {
      /* dest has two children*/
      point = dest;
      /* find largest node at left child */
      target = dest->left;
      while (!target->rightThread) {
        point = target;
        target = target->right;
      }
      /* using replace mode*/
      dest->key = target->key;
    }
    if (point->key >= target->key) {
      if (target->rightThread && target->leftThread) {
        point->left = target->left;
        point->leftThread = true;
      } else if (target->rightThread) {
        Node *largest = target->left;
        while (!largest->rightThread) {
          largest = largest->right;
        }
        largest->right = point;
        point->left = target->left;
      } else {
        Node *smallest = target->right;
        while (!smallest->leftThread) {
          smallest = smallest->left;
        }
        smallest->left = target->left;
        point->left = target->right;
      }
    } else {
      if (target->rightThread && target->leftThread) {
        point->right = target->right;
        point->rightThread = true;
      } else if (target->rightThread) {
        Node *largest = target->left;
        while (!largest->rightThread) {
          largest = largest->right;
        }
        largest->right = target->right;
        point->right = target->left;
      } else {
        Node *smallest = target->right;
        while (!smallest->leftThread) {
          smallest = smallest->left;
        }
        smallest->left = point;
        point->right = target->right;
      }
    }
    delete target;
  }