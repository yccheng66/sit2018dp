#include "total_size_visitor.h"
#include "file.h"
#include "folder.h"

void TotalSizeVisitor::visit(File * file) {
  _size += file -> size();
}

void TotalSizeVisitor::visit(Folder * folder) {
  _size += folder -> size();
  for (int i=0; i < folder->numberOfChildren(); i++)
    folder->getChild(i)->accept(this);
}
