#include "binary_search_tree.h"

binary_search_tree::binary_search_tree(){
  root = NULL;
}

binary_search_tree::~binary_search_tree(){
  //destructor helper call
}
void binary_search_tree::set(string key, int data){

  if (root == NULL)//insert at front
    root = new Node(key,data);
  else if(find(key) != -1){//if the data is already in the tree
    Node *traverse = root;
    while (traverse -> data != data){
      if(traverse ->left->data > data)
  	traverse = traverse ->left;
      else if(traverse->right->data < data)
  	traverse = traverse->right;
    }
    traverse->data = data;
  }
  else//search for the correct place to insert
    set_helper(root, key, data);

    }
void binary_search_tree::set_helper(Node *current, string key, int data){
  if(current != NULL){
  if(current -> data > data){
    if(current ->left != NULL)
      set_helper(current->left, key, data);
    else {;
      current->left = new Node(key, data);
    }
  }   
  else if( current->data < data){
    if(current ->right != NULL)
      set_helper(current->right, key, data);
    else{
      current->right = new Node(key, data);
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
    cout << "The data for ["  << current->key << "] is " << current->data
	 << endl;
    print_helper(current->right);
  }
}
void  binary_search_tree::min(){
  if (root == NULL)
    cout << "This is an empty tree!" << endl;
  else 
    cout << min_helper(root) << endl;


}
int binary_search_tree::min_helper(Node *current){
  if (current != NULL && current->left != NULL)
    min_helper(current->left);
  else
    return current->data;

}

void  binary_search_tree::max(){
 if (root == NULL)
    cout << "This is an empty tree!" << endl;
  else 
    cout << max_helper(root) << endl;
}
int binary_search_tree::max_helper(Node *current){
  if (current != NULL && current->right != NULL)
    max_helper(current->right);
  else
    return current->data;
}
