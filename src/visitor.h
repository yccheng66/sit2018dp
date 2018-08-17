#ifndef VISITOR_H
#define VISITOR_H

class File;
class Folder;

class Visitor{
public:
  virtual void visit(File * file) = 0;
  virtual void visit(Folder * folder) = 0;
};

#endif
