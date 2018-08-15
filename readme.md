## Design Patterns: an exercise in object-oriented file system API
### Summer, 2018
### Prof Y C Cheng
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech, Taiwan

# Problem

The file system is used in many apps ranging from document editors (e.g., Atom), file/directory browser, file sync/storage applications (e.g., Dropbox), etc. In these applications, it is necessary to open/save document(s) from/to a selected location in the file system. Many operations on the file system are needed; for example, adding/deleting a file to/from a directory; moving selected files from one directory to another, searching files with a given name, compressing or encrypting a file or a directory, etc. Also, certain information about the files and directories are often needed, for example, the storage space used by a file or a directory, the organization of a directory, etc.

File systems differ in different operating systems. In this problem, we shall assume that Unix file system is used. To be sure, it is possible to provide all of the above operations by invoking system calls and functions that comes in C-binding on Unix systems. Unfortunately, the API bindings are usually terse and difficult to understand and are not suitable for use in the applications. Thus, the problem is to develop an object-oriented API in C++ that is easier to understand and work with. In particular, we want to organize the file system into a tree structure, and allow the client of the API to use nodes inside the tree uniformly. We also want it to be easy to add various operations to the file system.

## Problem analysis, design problems, and design patterns

- Understanding the problem
  - lstat, stat, S_ISDIR, S_ISREG, S_ISLNK
  - name, size, time, etc.

## Organizing folders and files into a tree structure and treating them uniformly from the client program with Composite

## Accessing folders and files with Iterator; find folder or file by name

## Adding symbolic link: Proxy

## Find by name with Visitor; additional examples of visitors

## The problem solved: review with basic OO principles
 - open-closed principle
 - programming to interface, not an implementation

## Notes
- (Eng) Project structure
- (Eng) How to do version control with git?
   - git init
   - git status
   - git add .
   - git commit -m "message"
   - git log --oneline
   - git checkout _commit_: checkout a previous commit
   - git branch _branch_: create a new branch
   - git checkout _branch_: switch to a branch
   - git branch : show all branches
   - git remote -v : show url of the remote
   - git remote rm origin; rm .git/FETCH_HEAD : unlink local from remote
- (Lan) Polymorphism
  - base class - derived class
  - pure virtual member functions in base class
  - overriding pure virtual functions in derived class
  - treating objects of derived classes like they are objects of base class through pointers or references
