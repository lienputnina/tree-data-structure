#ifndef TreeObject_h
#define TreeObject_h

#include "TreeNode.h"

class TreeObject {
private:
  /*
   Pointers to the root and leaf nodes to identify the first and last elements
   of the tree. This is necessary to move the left and right node
   pointers during the manipulation with the tree.
   */
  TreeNode *rootNode;
  TreeNode *leafNode;

  unsigned int numberOfChildren; // ? number of child nodes
  int nodeCount;                 // ? current number of children for a node.
public:
  TreeObject(unsigned int numberOfChildren); // ?

  void AddNode(TreeNode &newNode, TreeNode uniqueId);
  TreeNode *DeleteNode(TreeNode uniqueId);

  /*
    ? Displays the tree as a multidimensional list - what does it mean?.
    Each node has type, name and id.
  */
  void PrintTree();
};

#endif