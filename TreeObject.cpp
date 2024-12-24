#include "TreeObject.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

TreeObject::TreeObject()
{
  RootNode = new TreeNode(1, 0, "Root", "d");
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
  Checking if the current node's uniqueId matches the target id.
  If the ids match, the function returns a pointer to the current node, ending the search.
  */
  if (currentNode->uniqueId == nodeId)
  {
    return currentNode;
  }
  /*
  Iterating through the nodeContainer of the current node.
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

  return nullptr;
}

/*
chatGPT helped to refactor this method. Previous problems:
1. There was no check for the existence of the parent node.
2. The result of FindNode was not being stored in a variable.
3. The nodeContainer was being accessed directly.
*/
void TreeObject::AddNode(int uniqueNodeId, int parentNodeId, string nodeName, string nodeType)
{
  // Checking, if there is already a node with the same id in the tree.
  TreeNode *targetNode = FindNode(RootNode, uniqueNodeId);

  if (targetNode != nullptr && targetNode->type == nodeType)
  {
    DeleteNode(uniqueNodeId);
  }

  else if (targetNode != nullptr && targetNode->type != nodeType)
  {
    cout << "A node with the id " << uniqueNodeId << " already exists. Please, choose a different id" << endl;
    return;
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
    cout << "Parent node with the id: " << parentNodeId << " is a leaf node. Leaf nodes cannot have children." << endl;
    return;
  };

  // Creating a new node with the required parameters.
  TreeNode newNode = TreeNode(uniqueNodeId, parentNodeId, nodeName, nodeType);

  // Adding the new node to the parent node's nodeContainer.
  parentNode->nodeContainer.push_back(newNode);
  cout << "Node " << newNode.name << " with the id: " << newNode.uniqueId << " successfully added as a child to the parent node with the id: " << parentNodeId << endl;
};

void TreeObject::DeleteNode(int id)
{
  // Checking, if the node with the specified uniqueId exists in the tree.
  TreeNode *nodeToDelete = FindNode(RootNode, id);
  TreeNode *parentNode = FindNode(RootNode, nodeToDelete->parentId);

  if (nodeToDelete == nullptr)
  {
    cout << "Node with the id: " << id << " does not exist." << endl;
    return;
  }

  if (parentNode == nullptr)
  {
    cout << "Parent node for the node with the id: " << id << " does not exist." << endl;
    return;
  }

  // Removing link from parent node
  int nodePosition = -1;
  for (int i = 0; i < parentNode->nodeContainer.size(); i++)
  {
    if (parentNode->nodeContainer[i].uniqueId == id)
    {
      nodePosition = i;
      break;
    }
  }
  parentNode->nodeContainer.erase(parentNode->nodeContainer.begin() + nodePosition);

  cout << "Node with the id: " << id << " successfully deleted." << endl;

  return;
};

/*
chatGPT helped to refactor this method. Previous problems:
Had redundant for loop, unnecessary currentNode declaration, no indentation,
Helped to refactor the indentation logic. I was mixing conditional logic and output logic.
Had unnecessary Condition for Parent Node Check,
Was incrementing the currentLevel for every child
*/
void TreeObject::PrintTreeNodes(TreeNode *currentNode, int currentLevel)
{
  if (currentNode == nullptr)
  {
    return;
  };

  string indentation(currentLevel * 4, ' '); // 4 tabs per level

  cout << indentation << currentNode->type << "(" << currentNode->uniqueId << ")" << " - " << currentNode->name << endl;

  if (currentNode->type == "f")
  {
    return;
  };

  /*
  Iterating through the nodeContainer of the current node and calling the PrintTreeNodes method
  recursively for each child node.
  */
  for (auto &childNode : currentNode->nodeContainer)
  {
    PrintTreeNodes(&childNode, currentLevel + 1);
  };
};

/*
chatGPT helped to refactor this method. Previous problems:
1. Had a redundant RootNode check
2. Had unnecessary for loop, where I was looping through the nodeContainer of the RootNode
3. Was manually iterating  through RootNode->nodeContainer
*/
void TreeObject::PrintTree(int uniqueNodeId)
{
  TreeNode *currentNode = FindNode(RootNode, uniqueNodeId);

  if (currentNode != nullptr)
  {
    PrintTreeNodes(currentNode, 1);
  }

  cout << endl;
};
