#include "TreeObject.h"
#include "TreeNode.h"
#include <iostream>

TreeObject::TreeObject(){
    // something happens here
};

void TreeObject::AddNode(TreeNode &newNode, TreeNode uniqueId) {
  /*
  1. Check, if tree is empty (no nodes)
  2. If empty, add the first node. This will be the root node
  3. If already has a node, add the second node. Before adding, check the node
  type. If it's "f", prevent adding more nodes
  */
  if (nodeCount == 0) {
    // add a Root node
    // TreeNode *Node = &newNode;
    // newNode.uniqueId = 1;
    // newNode.highLvlId = 0;

  } else if (newNode.type == "f") {
    cout << "Cannot add any more nodes. " << endl;
  } else {
    // some more code
    // TreeNode *NextNode = &newNode;
    // newNode.uniqueId = ;
    // newNode.highLvlId = 1;
  }

  nodeCount++;
}