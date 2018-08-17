#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"
// Create class for holding Folder information
#include "iterator.h"
#include <sys/stat.h>
#include <vector>


class Folder : public Node {
public:
  class FolderIterator : public Iterator {
  public:
    FolderIterator(Folder *f):_theFolder(f) {
    }
    virtual void first () {_current = 0;}
    virtual void next () {_current ++;}
    virtual bool isDone() {return _current >= _theFolder->numberOfChildren();}
    virtual Node * currentItem() {
      return _theFolder->getChild(_current);
    }
  private:
    int _current;
    Folder * _theFolder;
  };

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

  Iterator * createIterator() {
    return new FolderIterator(this);
  }
};
#endif
