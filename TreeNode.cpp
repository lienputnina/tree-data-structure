// Tree node implementation
#include "TreeNode.h"

TreeNode::TreeNode(int uniqueNodeId, int highLvlNodeId, string nodeName,
                   string nodeType) {

  uniqueId = uniqueNodeId = 0;
  highLvlId = highLvlNodeId = 0;
  name = nodeName = "";
  type = nodeType = "";

  nodeType = "f" ? "cannot add more children" : ""; // here or in main?
  //   nodeName.contains(",") ? "Invalid name. Write one without commas"
}