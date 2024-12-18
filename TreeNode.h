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
  string uniqueId;
  string highLvlId; // ParentNode id
  string name;      // node name
  string type;      // node type. d- katalogs, f - fails

  TreeNode(string uniqueId, string highLvlId, string name, string type);
};

#endif