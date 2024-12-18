#ifndef TreeObject_h
#define TreeObject_h

#include "TreeNode.h"

class TreeObject {
private:
  int nodeCount; // number of child nodes
  TreeNode *rootNode;
  TreeNode *childNode;

public:
  TreeObject(); // what parameter here?

  void AddNode(TreeNode &newNode,
               TreeNode uniqueId); // with known id. Where to put the id?
  void deleteNode(TreeNode uniqueId);

  /*
    Displays the tree as a multidimensional list.
    Each node has type, name and id.
  */
  void PrintTree();
};

#endif