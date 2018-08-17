#ifndef TOTAL_SIZE_VISITOR_H
#define TOTAL_SIZE_VISITOR_H
#include "visitor.h"
#include "file.h"

class TotalSizeVisitor : public Visitor{
public:
  TotalSizeVisitor() {
    _size = 0;
  }
  void visit(File * file);
  void visit(Folder * folder);
  int getResult() {
    return _size;
  }

private:
  int _size;
};
#endif
