#include "skiplist.h"
#include "random.h"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <unordered_map>

using namespace std;

SNode::SNode(int val) : val(val) {
}

SNode::SNode(const SNode &other) : val(other.val), next(other.next) {
}

/**
    Constructor for a SkipList

    @param levels to initialize levels
    @param probability to initialize probability
*/

SkipList::SkipList(int levels, int probability) : levels(levels) {
  this -> probability = probability;
  head = nullptr;
}

/**
    Copy constructor for SkipList

    @param SkipList &other as a reference to the SkipList being copied
*/

SkipList::SkipList(const SkipList &other) : levels(other.levels){
  head = new SNode(other.head->val);
  SNode* cur = other.head->next[0];
    while(cur != nullptr) {
        add(cur->val);
        cur = cur->next[0];
    }
}

/*
    Destructor for the SkipList class
*/
SkipList::~SkipList() { 
  SNode* cur = head;
    while(cur != nullptr) {
        SNode* next = cur->next[0];
        delete cur;
        cur = next;
    }
}

// checks if the value needs to be inserted at a higher level
bool SkipList::shouldInsertAtHigherLevel() const {
  return probability >= Random::random() % 100;
}

/**
    Function to add a SkipNode into the SkipList

    @param int val as the value for the SkipNode
*/
void SkipList::add(int val) {
  if(head == nullptr) {
    head = new SNode(val);
    levels = 1;
  } else {
    SNode* nextNode = new SNode(val);
    int insertLevel = 1;
    while(shouldInsertAtHigherLevel()) {
        insertLevel++;
    }
    if(insertLevel > levels) {
      levels = insertLevel;
    }
    vector<SNode*> passedNodes(levels + 1, nullptr);
    SNode* cur = head;
    for(int i = levels; i >=0; i--) {
        while(cur->next[i] != nullptr && cur->next[i]->val < val) {
          cur = cur->next[i];
        }
        passedNodes[i] = cur;
    }
    for(int i = 0; i < insertLevel; i++) {
        nextNode->next[i] = passedNodes[i]->next[i];
        passedNodes[i]->next[i] = nextNode;
    }
  } 
}

/**
    Takes a vector of values and calls the add function to add them to the SkipList

    @param values as a constant reference to the list of values to be used for nodes
*/
void SkipList::add(const vector <int> &values){
  for(int toAdd : values) {
        add(toAdd);
    }
}

/**
 * Removes a node with the specified value from the SkipList
 * 
 * @param val the value to be removed
 * @return true if the value was found and removed successfully,
 *         false otherwise
 * 
 * @pre the skiplist is intialized and contains nodes
 * @post If the value is found in the SkipList, it is removed along with its associated node.
 *       The links between the nodes are adjusted accordingly.
 *       If the value is not found, the SkipList remains unchanged.
*/
bool SkipList::remove(int val) {
  SNode *current = head;

  SNode *update[levels + 1];

  for(int i = levels; i >= 0; i--){
    while(current -> next.size() > i && current -> next[i] != nullptr && current -> next[i] -> val < val){
      current = current -> next[i];
      
    }

    update[i] = current;
  }

  current = current -> next[0];

  if(current != nullptr && current -> val == val){
    for(int i = 0; i <= levels; i++){
      if(update[i] -> next[i] != current){
        break;
      }
      update[i] -> next[i] = current -> next[i]; 

    }

    while(levels > 0 && head -> next[levels] == 0){
      levels--;
    }

    delete current;
    return true;
  }

return false;

}  

/**
 * Searches for the specified value from the SkipList
 * 
 * @param val the value to look for
 * @return true if the value was found,
 *         false otherwise
 * 
 * @pre the skiplist is intialized and contains nodes
 * @post If the value is found in the SkipList, return
 * true
*/
bool SkipList::contains(int val) const {
  SNode *current = head;

  for(int i = levels; i >= 0; i--){
    while(current -> next.size() > i && current -> next[i] != nullptr && current -> next[i] -> val < val){
      current = current -> next[i];
    }

  }
  current = current->next[0];

  if(current != nullptr && current -> val == val){
    return true;
  }

  return false;

}

ostream &operator<<(ostream &out, const SkipList &skip){
  SNode* cur = skip.head;
  out << "[level: " << skip.levels << "] ";
  while(cur != nullptr) {
    out << cur->val;
    if(!(cur->next.empty()) && cur->next[0] != nullptr) {
      out << "-->";
      cur = cur->next[0];
    } else {
      break;
    }
  }
  out << "-->nullptr\n";
  return out;
}