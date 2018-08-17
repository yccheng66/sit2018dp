// Create class for holding File information
#ifndef FILE_H
#define FILE_H

#include <sys/stat.h>
#include "node.h"
#include "total_size_visitor.h"

class File : public Node {
public:
  File(const char * path): Node(path) {
  }

  void accept(Visitor * visitor) {
    visitor -> visit(this);
  }
};
#endif
