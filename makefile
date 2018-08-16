.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
BIN=bin
OBJ=obj
SRC=src
TEST=test

all: directories $(BIN)/ut_main

$(BIN)/ut_main: $(TEST)/ut_main.cpp $(OBJ)/total_size_visitor.o $(TEST)/ut_fs.h $(SRC)/node.h $(SRC)/visitor.h $(SRC)/file.h $(SRC)/total_size_visitor.h
	$(CC) $(CFLAGS) $< -o $(OBJ)/total_size_visitor.o $@ $(LIBS)

$(OBJ)/total_size_visitor.o: $(SRC)/total_size_visitor.cpp
	$(CC) -c $(SRC)/total_size_visitor.cpp
directories:
	mkdir -p bin obj

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc $(SRC)/* $(TEST)/*
