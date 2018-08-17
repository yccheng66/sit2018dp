#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"
// Create class for holding Folder information

#include <sys/stat.h>
#include <vector>

class Folder : public Node {
private:
  std::vector<Node *> _children;

public:
  Folder(const char * path):Node(path) {
  }

  void add(Node * n) {
    _children.push_back(n);
  }

  Node * getChild(int i) {
    return _children[i];
  }

  int numberOfChildren () const {
    return _children.size();
  }

  void accept(Visitor * visitor) {
    visitor->visit(this);
  }
};
#endif
