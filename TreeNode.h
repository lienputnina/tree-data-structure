#ifndef TreeNode_h
#define TreeNode_h

#include <string>
#include <vector>
using namespace std;

class TreeNode
{

public:
  int uniqueId; // id for each node.
  int parentId; // ParentNode id (augstāka_līmeņa_mezgla_id)
  string name;
  string type; // node type. d- katalogs, f - fails

  vector<TreeNode> nodeContainer;

  TreeNode(int uniqueId, int parentId, string name, string type);
};

#endif