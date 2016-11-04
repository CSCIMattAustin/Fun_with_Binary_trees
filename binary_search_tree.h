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

 public:
    binary_search_tree();
    ~binary_search_tree_h();  
    void set(string key, int data);
    int find(string key);
    void print();
    void min();
    void max();
    void save_file(string file);
    void delete(string key);
};


#endif //BINARY_SEARCH_TREE_H
