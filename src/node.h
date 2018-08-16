#ifndef NODE_H
#define NODE_H

// TO DO: refactor file 15 Aug 18

#include <string>

class Visitor;

class Node {
public:
  virtual int size() const = 0;
  virtual ~Node(){}
  virtual void add(Node * n) {
    throw std::string("Not Allowed");
  }
  virtual Node * getChild(int x) {
    throw std::string("Not Allowed");
  }
  virtual int totalSize() const {
    return size();
  }
  virtual void accept(Visitor * visitor) = 0;
};

#endif
