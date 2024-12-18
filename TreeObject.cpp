#include "TreeNode.h"
#include <string>

TreeNode::TreeNode(string uniqueNodeId, string highLvlNodeId, string nodeName,
                   string nodeType) {

  uniqueId = uniqueNodeId;
  highLvlId = highLvlNodeId;
  name = nodeName;
  type = nodeType;

  nodeType = "f" ? "cannot add more children" : ""; // here or in main?
  //   nodeName.contains(",") ? "Invalid name. Write one without commas"
}