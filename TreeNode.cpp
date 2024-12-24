#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(int uniqueNodeId, int parentNodeId, string nodeName,
                   string nodeType)
{
  uniqueId = uniqueNodeId;
  parentId = parentNodeId;
  name = nodeName;
  type = nodeType;
  nodeContainer = {};
};
