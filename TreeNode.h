#ifndef TreeNode_h
#define TreeNode_h

#include <string>
using namespace std;

class TreeNode {
public:
  /*
    Fails - leaf. Has no descendants
    Each node with type "katalogs" can have any number of children - other nodes
    or leaves.
    Root node has level 0 (no edges to root)
    An array that holds all the children of a node - in main or TreeObject?
  */
  int uniqueId;  // number in the structure - 1st, 2nd etc.
  int highLvlId; // ParentNode id
  string name;   // node name
  string type;   // node type. d- katalogs, f - fails

  TreeNode *leftNode;
  TreeNode *rightNode;

  TreeNode(int uniqueId, int highLvlId, string name, string type);
};

#endif