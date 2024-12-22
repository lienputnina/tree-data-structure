#include "TreeNode.h"

TreeNode::TreeNode(unsigned uniqueNodeId, unsigned int parentNodeId, string nodeName,
                   string nodeType)
{

  uniqueId = uniqueNodeId ? uniqueNodeId : 0;
  parentId = parentNodeId ? parentNodeId : 0;

  name = nodeName.empty() ? nodeName : "";
  type = nodeType.empty() ? nodeType : "";

  nodeContainer = {};
};
