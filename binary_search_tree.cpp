#include "binary_search_tree.h"

binary_search_tree::binary_search_tree(){
  root = NULL;
}

binary_search_tree::~binary_search_tree(){
  if (root != NULL){
    destructor_helper(root);
    root = NULL;
  }
}
void binary_search_tree::destructor_helper(Node *current){
  if (current != NULL){
    destructor_helper(current->left);
    destructor_helper(current->right);
    delete current;
  }

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
  
  return find_helper(root, key);
}
int binary_search_tree::find_helper(Node *current, string key){
  if (current -> key != key){  
    if (current -> left != NULL && current->key > key)
      return find_helper(current ->left, key);
    else if (current -> right != NULL && current->key < key)
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
    return min_helper(current->left);
  
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
    return max_helper(current->right);
  
  return current->data;
}
void binary_search_tree::read_from_file(string file){
  string key;
  ifstream infile(file.c_str());
  infile >> key;
  while(infile){
    remove_bad_char(key);
    if (key != ""){    
      if (root == NULL){
	root = new Node(key, 1);
      }
      else if(find(key) != (-1)){
	read_find(root,key);
      }
      else{	
	read_helper(root, key);
      }
    }
    infile >> key; 
  }
  infile.close();
}
void binary_search_tree::read_find(Node *current, string key){
  if (current->key < key && current->right != NULL)
    read_find(current->right, key);
  else if(current->key > key && current->left != NULL)
    read_find(current->left, key);
  else
    current->data++;
}
  

void binary_search_tree::read_helper(Node *current, string key){
  if(current -> key > key){
    if(current->left != NULL)
      read_helper(current->left, key);
    
    else if (current->left == NULL){
      current->left = new Node(key, 1);	
    }
  } 
  else if(current->key < key){
    if (current->right != NULL)
      read_helper(current->right, key);
    
    else if (current ->right == NULL){
      current->right = new Node(key, 1);
    }
  }
}



void binary_search_tree::remove_bad_char(string &key){
  unsigned MAX_POSITION = 100;
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
void binary_search_tree::remove(string key){
  if (root == NULL)
    return;
  else
    remove_helper(root, key);

}
void binary_search_tree::remove_helper(Node *&current, string key){
  if (current != NULL){
    if (current ->key > key)
      remove_helper(current->left, key);
    else if (current->key < key)
      remove_helper(current->right, key);
    else if (current->left == NULL && current ->right == NULL){
      delete current;
      current = NULL;
    }
    else if (current->left == NULL && current->key == key){
      Node *temp;
      temp = current->right;
      delete current;
      current = temp;
    }
    else if (current->right == NULL && current->key == key){
      Node *temp;
      temp = current->right;
      delete current;
      current = temp;
    }
    else if (current->right != NULL && current->left != NULL && current->key == key){
      Node *&traverse = current->left;
      while(traverse->right != NULL)
	traverse = traverse->right;
      current->key = traverse->key;
      current->data = traverse->data;
      delete traverse;
      traverse = NULL;
    }
  }
}
