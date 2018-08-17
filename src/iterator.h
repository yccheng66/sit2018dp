#ifndef ITERATOR_H
#define ITERATOR_H

class Node;

class Iterator {
public:
  virtual void first () = 0;
  virtual void next () = 0;
  virtual bool isDone() = 0;
  virtual Node * currentItem() = 0;
};

class NullIterator : public Iterator {
public:
  virtual void first () {}
  virtual void next () {}
  virtual bool isDone() {return true;}
  virtual Node * currentItem() {throw std::string("no current item");}
};

#endif
