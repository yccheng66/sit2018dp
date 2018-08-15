// TO DO: refactor file 15 Aug 18
class Node {
public:

  virtual int size() const = 0;
  virtual ~Node(){}
};

// Create class for holding Folder information
class Folder : public Node {
private:
  // Member data for folder size
  int _size;

public:
  Folder(const char * path) {
    struct stat st;
    stat(path, &st);
    _size = st.st_size;
  }

  int size() const {
    return _size;
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
