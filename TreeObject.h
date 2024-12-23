#ifndef TreeObject_h
#define TreeObject_h

#include "TreeNode.h"
#include <vector>
using namespace std;

class TreeObject
{
private:
  int nodeCount;    // current number of nodes in a tree.
  int currentLevel; // current tree level.

  // Method for traversing the child nodes.
  void TraverseTree(TreeNode *currentNode, int currentLevel);

public:
  TreeObject();
  ~TreeObject();

  TreeNode *RootNode;

  // method for finding a node in the tree.
  TreeNode *FindNode(TreeNode *currentNode, int nodeId);

  void AddNode(unsigned int uniqueNodeId, unsigned int parentNodeId, string nodeName, string nodeType);
  TreeNode *DeleteNode(unsigned int uniqueNodeId);

  void PrintTree();
};

#endif