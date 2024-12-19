#include "TreeObject.h"
#include "TreeNode.h"
#include <iostream>

TreeObject::TreeObject(unsigned int childCount) {
  numberOfChildren = childCount;
  nodeCount = 0;
  rootNode = nullptr;
  leafNode = nullptr;
};

// Jauna mezgla pievienošana mezglam ar zināmu identifikatoru (parent id)
void TreeObject::AddNode(TreeNode &newNode, TreeNode uniqueId) {
  // todo: Extra stuff: Check, whether the node is a leaf node and smth else
  // todo: figure out about the id
  if (nodeCount >= numberOfChildren || newNode.type == "f") {
    cout << "No more child nodes can be added" << endl;
    return;
  }

  if (nodeCount == 0) {
    /*
    First element in the queue.
    Since the new node is the only node, it is both the root node and the
    leaf node.
   */
    rootNode = leafNode = &newNode;

  } else {
    // * might need to change the logic a bit (since this is a tree)
    //* Feel like we need more here
    /*
    Adding the new node to the end of the tree:
    1. Linking the new node to the current leaf
    2. Linking the current leaf to the new node
    3. Updating the leaf to the new node
   */
    newNode.leftNode = leafNode;
    leafNode->rightNode = &newNode;
    leafNode = &newNode;

    /*
    Updating the higher level id (parent id).
    Since the parent is one level above the child node, its id number will be
    smaller.
    */
    //* Not sure what to do here. How can I know what ID to pass to the new node
    //* as a user?
    newNode.uniqueId = newNode.uniqueId + 1;
    newNode.highLvlId = newNode.highLvlId - 1;
  }

  nodeCount++;
}