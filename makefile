.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
BIN=bin
OBJ=obj
SRC=src
TEST=test

all: directories $(BIN)/ut_main

$(BIN)/ut_main: $(TEST)/ut_main.cpp $(OBJ)/total_size_visitor.o $(TEST)/ut_fs.h \
	$(SRC)/node.h $(SRC)/visitor.h $(SRC)/file.h $(SRC)/total_size_visitor.h \
	$(SRC)/find_first_by_name_visitor.h
	$(CC) $(CFLAGS) $<  $(OBJ)/total_size_visitor.o -o $@ $(LIBS)

$(OBJ)/total_size_visitor.o: $(SRC)/total_size_visitor.cpp $(SRC)/total_size_visitor.h
	$(CC) -c $< -o $@
directories:
	mkdir -p bin obj

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc $(SRC)/* $(TEST)/*
