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
  if (root == NULL)//insert at front
    root = insert_node;
  else if(find(key) != -1){//if the key is already in the tree
    Node *traverse = root;
    while (traverse -> key != key){
      if(traverse ->left->key > key)
  	traverse = traverse ->left;
      else if(traverse->right->key < key)
  	traverse = traverse->right;
    }
    traverse->data = data;
  }
  else//search for the correct place to insert
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
  else
    return find_helper(root, key);
}
int binary_search_tree::find_helper(Node *current, string key){
  if (current -> key != key){  
    if (current -> left != NULL && current->left->key > key)
      return find_helper(current ->left, key);
    else if (current -> right != NULL && current->right->key < key)
      return find_helper(current ->right, key);
    else
      return -1;
  }
  return current -> data;
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
