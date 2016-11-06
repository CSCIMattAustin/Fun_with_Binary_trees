#include "binary_search_tree.h"

binary_search_tree::binary_search_tree(){
  root = NULL;
}

binary_search_tree::~binary_search_tree(){
  //destructor helper call
}
void binary_search_tree::set(string key, int data){
  Node *insert_node = new Node;
  insert_node->data = data;
  insert_node->key = key;
  if (root == NULL)
    root = insert_node;
  else if(find(key) == data){
    Node *traverse = root;
    while(traverse -> key != key){
      if(traverse ->left->key > key)
	traverse = traverse ->left;
      else if(traverse->right->key < key)
	traverse = traverse->right;
    }
    traverse->data = data;
    }
  else
    set_helper(root, key, data);

    }
void binary_search_tree::set_helper(Node *current, string key, int data){
  if(current != NULL){
    if(current -> key > key){
      if(current ->left != NULL)
	set_helper(current->left, key, data);
      else {
      Node *insert = new Node;
	insert->data = data;
	insert->key = key;
	current->left = insert;
      }
    }
    else if( current->key < key){
      if(current ->right != NULL)
	set_helper(current->right, key, data);
      else{
	Node *insert = new Node;
	insert->data = data;
	insert->key = key;
	current->right = insert;
      }
    }
  }
}
int binary_search_tree::find(string key){
  if(root == NULL)
    return -1;
  else if(root -> key == key)
    return root->data;
  else {
    Node *traverse = root;
    while(traverse -> key != key){
      if(traverse ->left->key > key)
	traverse = traverse ->left;
      else if(traverse->right->key < key)
	traverse = traverse->right;
    }
    return traverse->data;
  }
}
void binary_search_tree::print(){
  if(root != NULL)
    print_helper(root);
  
}
void binary_search_tree::print_helper(Node *current){
  if(current != NULL){
    print_helper(current->left);
    cout << "The key is " << current->key << "and the data is " << current->data
	 << endl;
    print_helper(current->right);
  }
}
