#ifndef FIND_FIRST_BY_NAME_VISITOR_H
#define FIND_FIRST_BY_NAME_VISITOR_H

#include "visitor.h"

class FindFirstByNameVisitor : public Visitor {
public:
  FindFirstByNameVisitor(std::string name): _name(name), _nodeFound(nullptr) {

  }
  void visit(File * file) {
    if (_name == file->name())
      _nodeFound = file;
  }
  void visit(Folder * folder) {
    if (_name == folder->name()) {
      _nodeFound = folder;
      return;
    }

    Iterator * it = folder->createIterator();
    for (it->first(); !it->isDone(); it->next())
      it->currentItem()->accept(this);
  }

  Node * getResult() {
    return _nodeFound;
  }

private:
  std::string _name;
  Node * _nodeFound;
};
#endif
