#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(unsigned uniqueNodeId, unsigned int parentNodeId, string nodeName,
                   string nodeType)
{

  uniqueId = uniqueNodeId ? uniqueNodeId : 0;
  parentId = parentNodeId ? parentNodeId : 0;

  name = nodeName.empty() ? nodeName : "";

  if (nodeName.length() <= 0)
  {
    cout << "Node name cannot be empty. Please provide a valid name." << endl;
    return;
  };

  type = nodeType.empty() ? nodeType : "";

  if (nodeType != "d" || nodeType != "f")
  {
    cout << "Node type must be either 'd' or 'f'. Please provide a valid type." << endl;
    return;
  };

  {
    cout << "Node name cannot be empty. Please provide a valid name." << endl;
    return;
  };

  if (nodeType.length() <= 0)
  {
    cout << "Node name cannot be empty. Please provide a valid name." << endl;
    return;
  };

  nodeContainer = {};
};
