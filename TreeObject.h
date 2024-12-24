#ifndef TreeObject_h
#define TreeObject_h

#include "TreeNode.h"
#include <vector>
using namespace std;

class TreeObject
{
private:
  // Method for traversing the child nodes.
  void PrintTreeNodes(TreeNode *currentNode, int currentLevel);

public:
  TreeObject();
  ~TreeObject();

  TreeNode *RootNode;

  // Method for finding a node in the tree.
  TreeNode *FindNode(TreeNode *currentNode, int nodeId);

  void AddNode(int uniqueNodeId, int parentNodeId, string nodeName, string nodeType);
  void DeleteNode(int uniqueNodeId);

  void PrintTree(int uniqueNodeId);
};

#endif