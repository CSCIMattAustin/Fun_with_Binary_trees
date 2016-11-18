# Author: Matthew Austin
# File: Makefile
# Date:11/15/2016
# Purpose:This is the Makefile for compiling my code

CC = g++ #compiler
CFLAGS = -c -Wall #these are the flags that specify how the code is to be compiled
TARGET = binst #this is the name of the executable
OFLAG = -o #this makes the executable

all:$(TARGET) #dependency for all

$(TARGET):binary_search_tree.o main.o # dependencies for TARGET
	$(CC) main.o binary_search_tree.o $(OFLAG) $(TARGET) 
        # final compilation

binary_search_tree.o:binary_search_tree.h binary_search_tree.cpp #dependencies for binary_search_tree.o
	$(CC) binary_search_tree.cpp $(CFLAGS)
        #compiles binary_search_tree.o

main.o: main.cpp binary_search_tree.h #dependencies for main.o
	$(CC) main.cpp $(CFLAGS)
        #compiles main.o

clean:
	rm *~ *.o $(TARGET)
        #cleans up unnecessary files
