#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Node{
 public:
  Node *left, *right;
  string key;
  int data;
  Node(string key, int data){
  left = NULL;
  right = NULL;
  this->key = key;
  this->data = data;
}

};

class binary_search_tree {
 private:
  Node *root;
 public:
    binary_search_tree();
    ~binary_search_tree();  
    void set(string key, int data);
    void set_helper(Node *current, string key, int value);
    int find(string key);
    int find_helper(Node *current, string key);
    void print();
    void print_helper(Node *current);
    void min();
    int min_helper(Node *current);
    void max();
    int max_helper(Node *current);
    void save_file(string file);
    void remove(string key);
};


#endif //BINARY_SEARCH_TREE_H
