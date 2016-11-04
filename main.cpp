
#include <iostream>
#include "binary_search_tree.h"

using namespace std;
int main(){
  binary_search_tree first_tree;
  string key;
  int data;
  char answer;
  cout << "WELCOME TO THE FANTASTIC TREE MANIPULATOR!!!!!!!"
       << "\n\nPlease enter one of the following options"
       << "\n\n(1)->Enter an item to be inserted into the tree"
       << "\n(2)->print the tree"
       << "\n(q)->quit";
  cin >> answer;
  while(answer != 'q'){
    if (answer == '1'){
    cout << "Please enter the key you would like to insert";
    cin >> key;
    cout << "Please enter the data you would like to be associated with the key";
    cin >> data;
    first_tree.set(key, data);
}
    else if(answer == '2')
      first_tree.print();
    cout << "WELCOME TO THE FANTASTIC TREE MANIPULATOR!!!!!!!"
	 << "\n\nPlease enter one of the following options"
	 << "\n\n(1)->Enter an item to be inserted into the tree"
	 << "\n(2)->print the tree"
	 << "\n(q)->quit";
    cin >> answer;
}
  return 0;
}
