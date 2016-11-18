/*Author: Matthew Austin
 *File: binary_search_tree.cpp
 *Date:11/15/2016
 *Purpose: This is the implementation for my binary_search_tree class
 */
#include "binary_search_tree.h"

binary_search_tree::binary_search_tree(){
  root = NULL;//initializes the tree to be empty
}

binary_search_tree::~binary_search_tree(){
  if (root != NULL){//empty tree
    destructor_helper(root);//recursive destructor call
    root = NULL;//reinitialize to an empty tree
  }
}
void binary_search_tree::erase_tree(){
  if (root == NULL)//empty tree
    return;//Nothing needs to be done
  else
    destructor_helper(root);//calls the destructor_helper to erase the tree
  root = NULL;//reinitialize to an empty tree
}

void binary_search_tree::destructor_helper(Node *current){
  if (current != NULL){//This prevents segmentation faults
    destructor_helper(current->left);//delete everything on my left
    destructor_helper(current->right);//delete everything on my right
    delete current;//delete the current Node
  }
}
void binary_search_tree::set(string key){
  if (root == NULL)//insert at front
    root = new Node(key,1);//assign with one because it is the first of this word
  else//search for the correct place to insert
    set_helper(root, key);//call to helper function
}
void binary_search_tree::set_helper(Node *current, string key){  
  if(current -> key > key){//key needs to go in the left subtree
    if(current ->left != NULL)//left subtree exists
      set_helper(current->left, key);//The place to insert hasn't been found
    else {//left subtree does not exist
      current->left = new Node(key, 1);//set as the left Node of current
    }
  }   
  else if( current->key < key){//key needs to go in the right subtree
    if(current ->right != NULL)//right subtree exists
      set_helper(current->right, key);//The place to insert hasn't been found
    else{//right subtree does not exist
      current->right = new Node(key, 1);//set as the right Node of current
    }
  }
}

int binary_search_tree::find(string key){
  if(root == NULL)
    return -1;//the tree is empty
  return find_helper(root, key);//try to find the Node
}
int binary_search_tree::find_helper(Node *current, string key){
  if (current -> key != key){  //checks to see if it is found before moving to the next Node
    if (current->key > key){//needs to be in the left subtree
      if (current -> left != NULL)//doesn' equal NULL
	return find_helper(current ->left, key);//move to the left Node if it isn't NULL
      else if (current->left == NULL){//does equal NULL
	current->left = new Node(key, 0);//Node wasn't found so insert with 0 as the data
	return current->left->data;//return the data which is 0
      }
    }
    else if (current->key < key){//needs to be in the right subtree
      if (current -> right != NULL)//doesn't equal NULL
      return find_helper(current ->right, key);//move to the right Node if it isn't NULL
      else if (current->right == NULL){//does equal NULL
	current->right = new Node(key, 0);//Node wasn't found so insert with 0 as the data
	return current->right->data;//return the data which is 0
      }
    
    }
  }
  return current->data;//this returns the data associated with
                                        //the key that was passed in if it was found
    }


void binary_search_tree::print(){
  if(root != NULL)//nonempty tree
    print_helper(root);
  
}
void binary_search_tree::print_helper(Node *current){
  if(current != NULL){//stops when current is NULL
    print_helper(current->left);//print the left subtree
    cout << "The count for ["  << current->key << "] is " << current->data
	 << endl;//print current
    print_helper(current->right);//print the right subtree
  }
}
void  binary_search_tree::min(){
  if (root == NULL)//empty tree
    cout << "This is an empty tree!" << endl;
  else //nonempty tree
    cout << min_helper(root) << endl;
}
string binary_search_tree::min_helper(Node *current){
  if (current->left != NULL)//if the leftmost Node hasn't been reached
    return min_helper(current->left);//recurse left
  return current->key;//return when it is found
}

void  binary_search_tree::max(){
  if (root == NULL)//empty tree
    cout << "This is an empty tree!" << endl;
  else //nonempty tree
    cout << max_helper(root) << endl;
}
string binary_search_tree::max_helper(Node *current){
  if (current->right != NULL)//if the rightmost Node hasn't been reached
    return max_helper(current->right);//recurse right
  
  return current->key;//return when it is found
}
void binary_search_tree::read_from_file(string file){
  string key;//variable to read in the keys
  ifstream infile(file.c_str());//file stream variable
  infile >> key;//priming read
  while(infile){//stops at the end of the file or other failstates
    remove_bad_char(key);//removes the unwanted characters from the words
    if (key != ""){    //This is so empty strings aren't counted
      if (root == NULL){//empty tree
	root = new Node(key, 1);
      }
      else if(find(key) != (-1)){//if the key is already in the tree
	read_find(root,key);
      }
      else{	//if the key isn't already in the nonempty tree
	read_helper(root, key);
      }
    }
    infile >> key;//secondary read 
  }
  infile.close();//closing the file
}
void binary_search_tree::read_find(Node *current, string key){
  if (current->key < key && current->right != NULL){//if the key goes before
                                                                                            //current's key and the key
                                                                                            //of the left Node isn't NULL
    read_find(current->right, key);//recurse right
  }
  else if(current->key > key && current->left != NULL){//if the key goes after
                                                                                                 //current's key and the key
                                                                                                 //of the right Node isn't NULL
    read_find(current->left, key);//recurse left
  }
  else
    current->data++;//increments the data for the word count
}
  

void binary_search_tree::read_helper(Node *current, string key){
  if(current -> key > key){//if the key goes in the left subtree
    if(current->left != NULL)//bounds checking
      read_helper(current->left, key);//recurse left
    else 
      current->left = new Node(key, 1);//set the Node to the left of current
  } 
  else if(current->key < key){//if the key goes in the right subtree
    if (current->right != NULL)////bounds checking
      read_helper(current->right, key);//recurse right
    else 
      current->right = new Node(key, 1);//set the Node to the right of current
  }
}
void binary_search_tree::remove_bad_char(string &key){
  unsigned const MAX_POSITION = 100;//This is an arbitrary number chosen because the
                                                                         //find function that is included in
                                                                         //the string library returns an
                                                                         //extremely large integer if
                                                                         //the character isn't found and this will
                                                                         //function as the stopping point for the
                                                                         //while loops.
  const int One_char = 1;//The function erase removes a specific number of characters
                                            //starting at at a given position and since find returns the
                                            //position of the passed-in character, erase will remove the
                                            //character at the position that find returns and only erases
                                            //1 character (One_char) which is what the second parameter
                                            //indicates.
  while(key.find(".") < MAX_POSITION)
    key.erase(key.find("."), One_char);//erase "."
  while(key.find(";") < MAX_POSITION)
    key.erase(key.find(";"), One_char);//erase ";"
  while(key.find("\"") < MAX_POSITION) 
    key.erase(key.find("\""), One_char);//erase "\"
  while(key.find(",") < MAX_POSITION)
    key.erase(key.find(","), One_char);//erase ","
  while(key.find("?") < MAX_POSITION)
    key.erase(key.find("?"), One_char);//erase "?"
  while(key.find(":") < MAX_POSITION)
    key.erase(key.find(":"), One_char);//erase ":"
  while(key.find("!") < MAX_POSITION)
    key.erase(key.find("!"), One_char);//erase "!"
  while(key.find("/") < MAX_POSITION)
    key.erase(key.find("/"), One_char);//erase "/"
  while(key.find("*") < MAX_POSITION)
    key.erase(key.find("*"), One_char);//erase "*"
  while(key.find("(") < MAX_POSITION)
    key.erase(key.find("("), One_char);//erase "("
  while(key.find(")") < MAX_POSITION)
    key.erase(key.find(")"), One_char);//erase ")"
  while(key.find("&") < MAX_POSITION)
    key.erase(key.find("&"), One_char); //erase "&"
  while(key.find("'") < MAX_POSITION)
    key.erase(key.find("'"), One_char); //erase "'"
  
}
void binary_search_tree::remove(string key){
  if (root == NULL)//empty tree
    return;
  else//nonempty tree
    remove_helper(root, key);//start at the root
}
void binary_search_tree::remove_helper(Node *&current, string key){
  if (current != NULL){//bounds checking
    if (current ->key > key)//value is in the left subtree
      remove_helper(current->left, key);//recurse left
    else if (current->key < key)//value is in the right subtree
      remove_helper(current->right, key);//recurse right
    else if (current->left == NULL && current ->right == NULL){//Case 1:No subtrees
      delete current;//delete the intended Node to delete
      current = NULL;//reassign to NULL
    }
    else if (current->left == NULL && current->key == key){//Case 2:No right subtree
     Node *temp;//temporary pointer for to conserve the right subtree
      temp = current->right;
      delete current;//delete the intended Node to delete
      current = temp;//reattach the right subtree
    }
    else if (current->right == NULL && current->key == key){//Case 3:No left subtree
      Node *temp;//temporary pointer for to conserve the right subtree
      temp = current->left;
      delete current;//delete the intended Node to delete
      current = temp;//reattach the left subtree
    }
    else if (current->right != NULL && current->left != NULL && current->key == key){//Case 4:both a right and left subtree
      Node *&traverse = current->left;//starting point for traversing
      while(traverse->right != NULL)//stopping point for traversing
	traverse = traverse->right;//traverse to the rightmost in the left subtree
      current->key = traverse->key;
      current->data = traverse->data;//change current's values to the
                                     //that of the left subtree's rightmost values
      if (traverse ->left != NULL){//if the biggest value on the left has a
	                           //left subtree
	Node *temp = traverse->left;//conserve the left subtree
	delete traverse;//delete the target Node
	traverse = temp;//reattach the left subtree
      }
      else{//No left subtree
	delete traverse;//delete the target Node
	traverse = NULL;//reassign to NULL
      }
    }
  }
}
void binary_search_tree::save_file(string file){
  if (root == NULL)//empty tree
    return;
  else {//nonempty tree
    ofstream oFile(file.c_str());//declaration of the file stream
    save_helper(root, oFile);//start writing at the root and use this file
    oFile.close();//close the file
  }
}
void binary_search_tree::save_helper(Node *current, ofstream &oFile){
  if(current != NULL){//bounds checking to avoid segmentation faults
    save_helper(current->left, oFile);//write the left subtree
    oFile  << current->key << " " << current->data << endl;//write the current
                                                           //Node
    save_helper(current->right, oFile);//write the right subtree
  }
}

int& binary_search_tree::operator[](string key){
  if (root == NULL){//empty tree
    root  = new Node(key, 0);//assign it with 0 as the data so it isn't counted
    return root->data;//return a reference to that integer
  }
  else{
    return operator_helper(root, key);//call the helper
  }
}
int& binary_search_tree::operator_helper(Node *&current, string key){
  if (current != NULL){//bounds checking
    if(current->key < key)//key is likely in the right subtree
      return operator_helper(current->right, key);//recurse right
    else if (current->key > key)//key is likely in the left subtree
      return operator_helper(current->left, key);//recurse left
    else if (current->key == key){//found the key
      return current->data;//return a reference to its data
    }
  }
  current = new Node(key, 0);//assign it with 0 as the data so it isn't counted
  return current->data;//return a reference to that integer
}
