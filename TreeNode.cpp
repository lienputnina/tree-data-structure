#include "TreeNode.h"

TreeNode::TreeNode(int uniqueNodeId, int highLvlNodeId, string nodeName,
                   string nodeType) {

  uniqueId = uniqueNodeId = 0;
  highLvlId = highLvlNodeId = 0;
  name = nodeName = "";
  type = nodeType = "";

  /*
    Initializing the pointers of the next and previous child node as NULL since
    this element is not in the tree yet (nothing to point to).
  */
  leftNode = nullptr;
  rightNode = nullptr;
}