#ifndef NODE_H
#define NODE_H

// TO DO: refactor file 15 Aug 18

#include <string>

class Visitor;

class Node {
private:
  // Member data for file size
  int _size;
  std::string _name;

public:
  Node(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
    int n = std::string(path).rfind('/');
    _name = std::string(path).substr(n+1);
  }

  int size() const {
    return _size;
  }

  std::string name() const {
    return _name;
  }

  virtual ~Node(){}

  virtual void add(Node * n) {
    throw std::string("Not Allowed");
  }
  virtual Node * getChild(int x) {
    throw std::string("Not Allowed");
  }

  virtual void accept(Visitor * visitor) = 0;
};

#endif
