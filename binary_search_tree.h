/*Author: Matthew Austin
 *File: binary_search_tree.h
 *Date:11/15/2016
 *Purpose:This is the header file for the binary_search_tree class. 
 */
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Node{//Node class
 public:
  Node *left, *right;//pointers to the next two Nodes
  string key;//key to find a specific Node
  int data;//the data that is associated with the key
  Node(string key, int data){//makes setting new nodes easier
    left = NULL;
    right = NULL;//initializing the pointers
    this->key = key;//sets the key
    this->data = data;//sets the data
  }

};

class binary_search_tree {
 private://These don't need to be accessed directly in main
  Node *root;//pointer to the root of the tree
  void destructor_helper(Node *current);
  //helps the destructor and erase_tree to allow reucursion
  //Pre-conditions:
  //    There is something in the tree
  //Post-conditions:
  //    There is nothing in the tree
  //
  void set_helper(Node *current, string key);
  ////helps the set function to allow recursion
  //Pre-conditions:
  //   There is something in the tree
  //Post-conditions:
  //   Sets the passed in key in the apropriate place
  //       
  int find_helper(Node *current, string key);
  //helper function for find returns the data associated with the key
  //Pre-conditions:
  //There is something in the tree
  //       
  string min_helper(Node *current);
  //helper for min to allow recursion
  //Pre-conditions:
  //There is someething in the tree
  //       
  string max_helper(Node *current);
  ////helper for max to allow recursion
  //Pre-conditions:
  //There is something in the tree
  //       
  void read_helper(Node *current, string key);
  // reads in a file and inserts in the tree in sorted order
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //There is now a tree filled with the strings from the file
  //       
  void read_find(Node *current, string key);
  //finds the key and increments the data if it is in there
  //Pre-conditions:
  //There is something in the tree and the key is in the tree
  //Post-conditions:
  //the correct data is incremented
  //       
  void remove_bad_char(string &key);
  //removes characters the unwanted characters to get an accurate count of the words in the file
  //Pre-conditions:
  //the string is a valid string
  //Post-conditions:
  //the key no longer has unwanted characters
  //       
  void print_helper(Node *current);
  //recursively prints the tree
  //Pre-conditions:
  //There is something in the tree
  //       
  void remove_helper(Node *&current, string key);
  //helps remove by finding the Node to remove based on the key
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //The Node with key is removed
  //       
  void save_helper(Node *current, ofstream &oFile);
  //Helps the save function write to the given file
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //the tree i written to a file
  //       
  int& operator_helper(Node *&current, string key);
  //operator overload helper function
  //Pre-conditions:
  //THere is something in the tree
  //Post-conditions:
  //returns a reference to an integer that is associated with key
  //       
 public:
  binary_search_tree();
  //sets the root to NULL for an empty tree
  //       
  ~binary_search_tree();
  //destructs the tree when the program ends
  //Post-conditions:
  //The tree is destructed and the program is terminated
  //       
  void set(string key);
  //sets the given key and data in the tree
  //Post-conditions:
  //The passed in key is inserted into the tree lexicographically
  //       
  int find(string key);
  //return the data that is associates with the key
  //Post-conditions:
  //returns the data associated with key
  //       
  void print();
  //prints the tree in lexicographical order
  //Post-conditions:
  //the tree is printed lexicographically
  //       
  void min();
  //prints the first key lexicographically
  //       
  void max();
  //prints the last key lexicographically
  //       
  void read_from_file(string file);
  //reads from a file and inserts into the tree
  //Post-conditions:
  //The strings from the file are inserted
  //       
  void save_file(string file);
  //Writes the tree to a given file
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //The tree is written to a file
  //       
  void remove(string key);
  //removes a specific Node and rearranges the Nodes if necessary
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //The given key is removed
  //       
  void erase_tree();
  //erases the entire tree
  //Pre-conditions:
  //There is something in the tree
  //Post-conditions:
  //The tree is deallocated
  //       
  int& operator[](string key);
  //overloads the []operator to return the data
  //Pre-conditions:
  //The key is in the tree
  //Post-conditions:
  //return a reference to the integer in the Node
  //       
  //       
  //       
};
#endif //BINARY_SEARCH_TREE_H
