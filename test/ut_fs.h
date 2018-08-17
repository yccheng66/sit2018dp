#ifndef UTFS_H
#define UTFS_H
#include <sys/stat.h>
#include "../src/node.h"
#include "../src/file.h"
#include "../src/folder.h"
#include "../src/visitor.h"
#include "../src/total_size_visitor.h"
#include "../src/find_first_by_name_visitor.h"

TEST(lstat, FolderThere) {
  const char * path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(160, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST(lstat, FolderNotThere) {
  const char * path = "./test_data/no_folder";
  struct stat st;
  ASSERT_NE(0, lstat(path, &st));
}

TEST(lstat, FileThere) {
  const char * path = "./test_data/hello.cpp";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(83, st.st_size);
  ASSERT_EQ(false, S_ISDIR(st.st_mode));
  ASSERT_EQ(true, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST(lstat, FileNotThere) {
  const char * path = "./test_data/no_file";
  struct stat st;
  ASSERT_NE(0, lstat(path, &st));
}

TEST(lstat, LinkThere) {
  const char * path = "./test_data/hello";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(14, st.st_size);
  ASSERT_EQ(false, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(true, S_ISLNK(st.st_mode));
}

TEST(lstat, LinkNotThere) {
  const char * path = "./test_data/no_link";
  struct stat st;
  ASSERT_NE(0, lstat(path, &st));
}

TEST(stat, LinkThere) {
  const char * path = "./test_data/hello";
  struct stat st;
  ASSERT_EQ(0, stat(path, &st));
  ASSERT_EQ(8432, st.st_size);
  ASSERT_EQ(false, S_ISDIR(st.st_mode));
  ASSERT_EQ(true, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

// Test for uniform handling of "Folder" and "File"
TEST(fileSystem, uniformity) {
  Node * test_data = new Folder("./test_data");
  Node * hello_dot_cpp = new File("./test_data/hello.cpp");

  ASSERT_EQ(160, test_data->size());
  ASSERT_EQ("test_data", test_data->name());
  ASSERT_EQ(83, hello_dot_cpp->size());
  ASSERT_EQ("hello.cpp", hello_dot_cpp->name());

  delete test_data;
  delete hello_dot_cpp;
}

TEST(fileSystem, tree) {

  Node * test_data = new Folder("./test_data");
  Node * hello_dot_cpp = new File("./test_data/hello.cpp");
  Node * folder_1 = new Folder("./test_data/folder_1");

  test_data->add(folder_1);
  test_data->add(hello_dot_cpp);

  ASSERT_EQ(folder_1, test_data->getChild(0));
  ASSERT_EQ(hello_dot_cpp, test_data->getChild(1));

  ASSERT_ANY_THROW(hello_dot_cpp->add(folder_1));
}

class VisitorTest : public ::testing::Test{
  protected: // fixture
    virtual void SetUp(){
      test_data = new Folder("./test_data");
      hello_dot_cpp = new File("./test_data/hello.cpp");
      folder_1 = new Folder("./test_data/folder_1");
      a_dot_out = new File("./test_data/folder_1/a.out");

      folder_1->add(a_dot_out);
      test_data->add(folder_1);
      test_data->add(hello_dot_cpp);
    }

  virtual void TearDown() {
    delete test_data;
    delete hello_dot_cpp;
    delete folder_1;
    delete a_dot_out;
  }

    Node * test_data;
    Node * hello_dot_cpp;
    Node * folder_1;
    Node * a_dot_out;

};

TEST_F (VisitorTest, totalSizeVisitor) {
  TotalSizeVisitor testVisitor, folderVisitor;
  hello_dot_cpp -> accept(&testVisitor);
  int value = testVisitor.getResult();
  ASSERT_EQ(83, value);
  folder_1->accept(&folderVisitor);
  ASSERT_EQ(8528, folderVisitor.getResult());
}

TEST_F(VisitorTest, findFirstByNameVisitor) {
  FindFirstByNameVisitor tv("a.out"), tv1("folder_1"), tv2("hello.cpp");
  test_data->accept(&tv);
  ASSERT_EQ(a_dot_out, tv.getResult());
  test_data->accept(&tv1);
  ASSERT_EQ(folder_1, tv1.getResult());
  test_data->accept(&tv2);
  ASSERT_EQ(hello_dot_cpp, tv2.getResult());
}

TEST_F(VisitorTest, Iterator) {
  Iterator * it = hello_dot_cpp->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  it = test_data->createIterator();
  it->first();
  ASSERT_EQ(folder_1, it->currentItem());
  it->next();
  ASSERT_EQ(hello_dot_cpp, it->currentItem());
  it->next();
  ASSERT_TRUE(it->isDone());
}


#endif
