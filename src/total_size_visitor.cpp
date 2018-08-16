#include "total_size_visitor.h"
#include "file.h"

void TotalSizeVisitor::visit(File * file) {
  _size = file -> size();
}
