#include "TreeObject.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

TreeObject::TreeObject()
{
  // used chatgpt to help optimize the RootNode initialization. Previously, I did not have it as a member variable
  // Also, it was not initialized with "new" keyword.
  RootNode = new TreeNode(1, 0, "Root", "d");
  nodeCount = 1;
};

TreeObject::~TreeObject()
{
  delete RootNode;
};

/*
This method traverses the tree recursively, starting from the current node, and finds the node with
a uniqueId matching the specified id. If the node is found, a pointer to it is returned; otherwise, the function returns nullptr.
Written by chatgpt.
*/
TreeNode *TreeObject::FindNode(TreeNode *currentNode, int nodeId)
{
  /*
  Checking if the current node's uniqueId matches the target id (the id of the node we want to add this one to).
  If the ids match, the function returns a pointer to the current node, ending the search.
  */
  if (currentNode->uniqueId == nodeId)
  {
    return currentNode;
  }
  /*
  Iterating through the nodeContainer of the current node.AddNode.AddNode
  For each child node in the container, we create a pointer to the node and call the FindNode function recursively.
  If the target node is found, we return the pointer to it, ending the search.
  */
  for (auto &childNode : currentNode->nodeContainer)
  {
    TreeNode *foundNode = FindNode(&childNode, nodeId);
    if (foundNode != nullptr)
    {
      return foundNode;
    }
  }
  cout << "Parent node with the id: " << nodeId << " does not exist." << endl;
  return nullptr;
}

/*
chatGPT helped to refactor this method. Previous problems:
1. I was not checking if the parent node existed.
2. Had not stored th result of FindNode anywhere
3. Was not accessing the nodeContainer of the parent node properly.
4. was not checking the leaf node condition properly.
*/
void TreeObject::AddNode(unsigned int uniqueNodeId, unsigned int parentNodeId, string nodeName, string nodeType)
{
  // todo: write the delete method
  // if type the same, replace the node with nre node and delete children (with the delete method), otherwise - error

  // Checking, if there is already a node with the same id in the tree.
  TreeNode *targetNode = FindNode(RootNode, uniqueNodeId);

  if (targetNode != nullptr && targetNode->type == nodeType)
  {
    // Replace the parent node with the new node;
    // Ignore the parentId  somehow
    return;
  }
  else if (targetNode->type != nodeType)
  {
    cout << "A node with the id " << uniqueNodeId << " already exists. Please, choose a different id" << endl;
  }

  /*
  Finding the parent node using the FindNode method.
  */
  TreeNode *parentNode = FindNode(RootNode, parentNodeId);

  if (parentNode == nullptr)
  {
    cout << "Parent node with the id: " << parentNodeId << " does not exist. Cannot add the new node" << endl;
    return;
  };

  // Checking, if the parent node is a leaf node ("f" is the type name for "fails").
  if (parentNode->type == "f")
  {
    cout << "This is a leaf node. Leaf nodes cannot have children." << endl;
    return;
  };

  // Creating a new node with the required parameters.
  TreeNode newNode = TreeNode(uniqueNodeId, parentNodeId, nodeName, nodeType);

  // Assigning a unique ID and parent ID to the new node.
  newNode.uniqueId = nodeCount++;
  newNode.parentId = parentNodeId;

  // Adding the new node to the parent node's nodeContainer.
  parentNode->nodeContainer.push_back(newNode);
  cout << "Node " << newNode.name << " with the id: " << newNode.uniqueId << " successfully added as a child to the parent node with the id: " << parentNodeId << endl;
};

TreeNode *TreeObject::DeleteNode(unsigned int uniqueNodeId)
{
  // Checking, if the node with the specified uniqueId exists in the tree.
  TreeNode *nodeToDelete = FindNode(RootNode, uniqueNodeId);

  if (nodeToDelete == nullptr)
  {
    cout << "Node with the id: " << uniqueNodeId << " does not exist." << endl;
    return nullptr;
  }

  // If the node is a leaf node (type = "f" or "fails"), delete the whole branch.
  if (nodeToDelete->type != "f")
  {
    for (auto &node : nodeToDelete->nodeContainer)
    {
      TreeNode *removedNode = DeleteNode(uniqueNodeId);
      return;
    }
  }

  // Delete the node itself.
  delete nodeToDelete;
  cout << "Node with the id: " << uniqueNodeId << " successfully deleted." << endl;

  return;
};
