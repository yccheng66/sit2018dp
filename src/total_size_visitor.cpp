#include "total_size_visitor.h"
#include "file.h"
#include "folder.h"

void TotalSizeVisitor::visit(File * file) {
  _size += file -> size();
}

void TotalSizeVisitor::visit(Folder * folder) {
  _size += folder -> size();
  Iterator * it = folder->createIterator();
  for (it->first(); !it->isDone(); it->next())
    it->currentItem()->accept(this);
}
