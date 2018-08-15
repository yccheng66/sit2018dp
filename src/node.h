// TO DO: refactor file 15 Aug 18
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
};

// Create class for holding Folder information
class Folder : public Node {
private:
  // Member data for folder size
  int _size;
  std::vector<Node *> _children;

public:
  Folder(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
  }

  int size() const {
    return _size;
  }

  void add(Node * n) {
    _children.push_back(n);
  }

  Node * getChild(int i) {
    return _children[i];
  }
};

// Create class for holding File information
class File : public Node {
private:
  // Member data for file size
  int _size;

public:
  File(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
  }

  int size() const {
    return _size;
  }
};
