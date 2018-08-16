#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"
// Create class for holding Folder information

#include <sys/stat.h>

class Folder : public Node {
private:
  // Member data for folder size
  int _size;
  std::vector<Node *> _children;

public:
  Folder(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
  }

  int size() const {
    return _size;
  }

  void add(Node * n) {
    _children.push_back(n);
  }

  Node * getChild(int i) {
    return _children[i];
  }

  int totalSize() const {
    int total = 0;
    for(int i=0; i<_children.size();i++) {
      total += _children[i]->totalSize();
    }
    total += this->size(); // Add size of this folder onto totalSize
    return total;
  }

  void accept(Visitor * visitor) {

  }
};
#endif
