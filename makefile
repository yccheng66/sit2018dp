.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_main

$(BIN)/ut_main: $(TEST)/ut_main.cpp $(TEST)/ut_fs.h
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

directories:
	mkdir -p bin

clean:
	rm -rf $(BIN)

stat:
	wc $(SRC)/* $(TEST)/*
