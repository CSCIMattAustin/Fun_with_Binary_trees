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
  else if(find_helper(root, key) != -1){//if the data is already in the tree
    Node *traverse = root;
    while (traverse->left != NULL && traverse ->right != NULL && traverse -> key != key){
      if(traverse->left != NULL && traverse ->key > key)
  	traverse = traverse ->left;
      else if(traverse->left != NULL && traverse->key < key)
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
      else {
	current->left = new Node(key, data);
	cout << current->left->key;
      }
    }   
    else if( current->data < data){
      if(current ->right != NULL)
	set_helper(current->right, key, data);
      else{
	cout << current->right->key;
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
    if (current -> left != NULL && current->key > key)
      return find_helper(current ->left, key);
    else if (current -> right != NULL && current->key < key)
      return find_helper(current ->right, key);
    else if (current->right == NULL && current->left == NULL)
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
void binary_search_tree::read_from_file(string file){
  string key;
  ifstream infile(file.c_str());
  infile >> key;
  if (root == NULL){
    cout << "root = NULL" << endl;
    root = new Node(key, 1);
    cout << root->key;
  }
  while(infile){
    remove_bad_char(key);
    if(find(key) != (-1)){
      read_find(root,key);
    }
    else{
	read_helper(root, key);
    }
    infile >> key; 
  }
  infile.close();
}
void binary_search_tree::read_find(Node *current, string key){
  if (current != NULL){
    if (current->key < key)
      read_find(current->right, key);
    else if(current->key > key)
      read_find(current->left, key);
    else
      current->data++;
  }
}
void binary_search_tree::read_helper(Node *current, string key){
  if(current -> key > key){
    if(current->left != NULL)
      read_helper(current->left, key);
    
    else{
      cout << "current->left = new Node(key, 1); " << endl;
      current->left = new Node(key, 1);	
      cout << current->left->key;
    }
  } 
  else if(current->key < key){
    if (current->right != NULL)
      read_helper(current->right, key);
    
    else{
      cout << "current->right = new Node(key, 1); " << endl;
      current->right = new Node(key, 1);
      cout << current->right->key;
    }
  }
}



void binary_search_tree::remove_bad_char(string &key){
  int MAX_POSITION = 100;
  while(key.find(".") < MAX_POSITION)
    key.erase(key.find("."), 1);
  while(key.find(";") < MAX_POSITION)
    key.erase(key.find(";"), 1);
  while(key.find("\"") < MAX_POSITION)
    key.erase(key.find("\""), 1);
  while(key.find(",") < MAX_POSITION)
    key.erase(key.find(","), 1);
  while(key.find("'") < MAX_POSITION)
    key.erase(key.find("'"), 1);
  while(key.find("?") < MAX_POSITION)
    key.erase(key.find("?"), 1);
  while(key.find(":") < MAX_POSITION)
    key.erase(key.find(":"), 1);
  while(key.find("!") < MAX_POSITION)
    key.erase(key.find("!"), 1);
  while(key.find("/") < MAX_POSITION)
    key.erase(key.find("/"), 1);
  while(key.find("-") < MAX_POSITION)
    key.erase(key.find("-"), 1);
  while(key.find("*") < MAX_POSITION)
    key.erase(key.find("*"), 1);
  while(key.find("(") < MAX_POSITION)
    key.erase(key.find("("), 1);
  while(key.find(")") < MAX_POSITION)
    key.erase(key.find(")"), 1);
  
  
}
