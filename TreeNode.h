#ifndef TreeNode_h
#define TreeNode_h

#include <string>
#include <vector>
using namespace std;

class TreeNode
{

public:
  unsigned int uniqueId; // number in the structure - 1st, 2nd etc.
  unsigned int parentId; // ParentNode id
  string name;           // node name
  string type;           // node type. d- katalogs, f - fails

  /*
  Asked Copilot where to place the vector for storing the child nodes.
  I wanted each node to have it upon its creation.
  */
  vector<TreeNode> nodeContainer;

  TreeNode(unsigned uniqueId, unsigned int parentId, string name, string type);
  TreeNode(); // default constructor
};

#endif