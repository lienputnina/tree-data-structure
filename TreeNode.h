#ifndef TreeNode_h
#define TreeNode_h

#include <string>
using namespace std;

class TreeNode {
public:
  int uniqueId;  // number in the structure - 1st, 2nd etc.
  int highLvlId; // ParentNode id
  string name;   // node name
  string type;   // node type. d- katalogs, f - fails

  /*
    Pointers to the left and right  (next and previous) child node.
  */
  TreeNode *leftNode;
  TreeNode *rightNode;

  TreeNode(int uniqueId, int highLvlId, string name, string type);
};

#endif