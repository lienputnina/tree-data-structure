// Tree object header
/*
Will hold all tree parts
*/
#ifndef TreeObject_h
#define TreeObject_h

class TreeObject {
private:
public:
  unsigned int numberOfChildren; // number of child nodes per node
  int nodeCount;
  int nodeEdgeCount;

  TreeObject();
};

#endif