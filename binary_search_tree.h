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
  void destructor_helper(Node *current);
  void set_helper(Node *current, string key, int value);
  int find_helper(Node *current, string key);
  string min_helper(Node *current);
  string max_helper(Node *current);
  void read_helper(Node *current, string key);
  void print_helper(Node *current);
  void remove_bad_char(string &key);
  void remove_helper(Node *&current, string key);
  void save_helper(Node *current, ofstream &oFile);
 public:
  binary_search_tree();
  ~binary_search_tree();  
  void set(string key, int data);
  int find(string key);
  void print();  
  void min();
  void max();  
  void read_from_file(string file);
  void read_find(Node *current, string key);   
  void save_file(string file);
  void remove(string key);
  void erase_tree();
  int operator[](string key);
};


#endif //BINARY_SEARCH_TREE_H
