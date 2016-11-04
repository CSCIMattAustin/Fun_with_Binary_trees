#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class binary_search_tree {
 private:
  struct Node{
    Node *left, *right;
    string key;
    int data;
  };
  Node *root;
 public:
    binary_search_tree();
    ~binary_search_tree();  
    void set(string key, int data);
    void set_helper(Node *current, string key, int value);
    int find(string key);
    void print();
    void print_helper(Node *current);
    void min();
    void max();
    void save_file(string file);
    void remove(string key);
};


#endif //BINARY_SEARCH_TREE_H
