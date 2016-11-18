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
 private:
  Node *root;//pointer to the root of the tree
  void destructor_helper(Node *current);//helps the destructor and erase_tree to allow reucursion
  void set_helper(Node *current, string key);//helps the set function to allow recursion
  int find_helper(Node *current, string key);//helps the find function to allw recursion
  string min_helper(Node *current);//helper for min to allow recursion
  string max_helper(Node *current);//helper for max to allow recursion
  void read_helper(Node *current, string key);//helper for the read function to set the items from the file
  void read_find(Node *current, string key);//finds the key and increments the data if it is in there
  void remove_bad_char(string &key);//removes characters the unwanted characters to get an accurate count of the words in the file
  void print_helper(Node *current);//recursively prints the tree
  void remove_helper(Node *&current, string key);//helps remove by finding the Node to remove based on the key
  void save_helper(Node *current, ofstream &oFile);//Helpf the save function write to the given file
  int& operator_helper(Node *&current, string key);//operator overload helper function
 public:
  binary_search_tree();//sets the root to NULL
  ~binary_search_tree();//destructs the tree when the program ends
  void set(string key);//sets the given key and data in the tree
  int find(string key);//return the data that is associates with the key
  void print();//prints the tree in lexicographical order
  void min();//prints the first key lexicographically
  void max();//prints the last key lexicographically
  void read_from_file(string file);//reads from a file and inserts into the tree
  void save_file(string file);//Writes the tree to a given file
  void remove(string key);//removes a specific Node and rearranges the Nodes if necessary
  void erase_tree();//erases the entire tree
  int& operator[](string key);//overloads the []operator to return the data
};


#endif //BINARY_SEARCH_TREE_H
