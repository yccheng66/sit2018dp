#ifndef VISITOR_H
#define VISITOR_H

class File;
class Visitor{
public:
  virtual void visit(File * file) = 0;

};

#endif
