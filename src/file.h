// Create class for holding File information
#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "total_size_visitor.h"

class File : public Node {
private:
  // Member data for file size
  int _size;

public:
  File(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
  }

  int size() const {
    return _size;
  }
  void accept(Visitor * visitor) {
    visitor -> visit(this);
  }
};
#endif
