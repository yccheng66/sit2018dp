#ifndef UTFS_H
#define UTFS_H
#include <sys/stat.h>
#include "../src/node.h"

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
//
// TEST(pathTest, LinkThere) {
//   const char * path = "./test_data/hello";
//   struct stat st;
//   ASSERT_EQ(0, lstat(path, &st));
//
//   int n = std::string(path).rfind('/');
//   std::string name = std::string(path).substr(n+1);
//   std::string pathToRoot = std::string(path).substr(0, n+1);
//   ASSERT_EQ("hello", name);
//   ASSERT_EQ("./test_data/", pathToRoot);
// }

// Test for uniform handling of "Folder" and "File"
TEST(fileSystem, uniformity) {
  Node * test_data = new Folder("./test_data");
  Node * hello_dot_cpp = new File("./test_data/hello.cpp");

  ASSERT_EQ(160, test_data->size());
  ASSERT_EQ(83, hello_dot_cpp->size());

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

TEST(fileSystem, totalSize) {

  Node * test_data = new Folder("./test_data");
  Node * hello_dot_cpp = new File("./test_data/hello.cpp");
  Node * folder_1 = new Folder("./test_data/folder_1");
  Node * a_dot_out = new File("./test_data/folder_1/a.out");

  folder_1->add(a_dot_out);
  test_data->add(folder_1);
  test_data->add(hello_dot_cpp);

  ASSERT_EQ(83, hello_dot_cpp->totalSize());
  ASSERT_EQ(8528, folder_1->totalSize());
}

#endif
