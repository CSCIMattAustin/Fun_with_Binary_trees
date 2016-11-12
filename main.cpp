
#include <iostream>
#include "binary_search_tree.h"

using namespace std;
void print_welcome();
int main(){
  string file;
  binary_search_tree first_tree;
  string key;
  int data;
  char answer;
  print_welcome();
  cout << "\n?";
  cin >> answer;
  while(answer != 'q'){
    if (answer == '1'){
    cout << "Please enter the key you would like to insert: ";
    cin >> key;
    cout << "Please enter the data you would like"
	 << "to be associated with the key: ";
    cin >> data;
    first_tree.set(key, data);
}
    else if(answer == '2')
      first_tree.print();
    else if(answer == '3')
      first_tree.min();
    else if(answer == '4')
      first_tree.max();
    else if(answer == '5'){
      cout << "Please enter a file to read from: ";
      cin >> file;
      first_tree.read_from_file(file);
    }
    else if (answer == '6'){
      cout << "Please enter the key of the item you wish to delete: ";
      cin >> key;
      first_tree.remove(key);
    }
    print_welcome();
    cout << "\n?";
    cin >> answer;
}
  return 0;
}
void print_welcome(){
  for (int i = 0; i<54; i++)
    cout << "-";
  cout << "\n|<<<<<WELCOME TO THE FANTASTIC TREE MANIPULATOR>>>>>>|"
       << "\n|<<<<<Please enter one of the following options>>>>>>|\n|";
  for(int i = 0; i<52; i++)
    cout << " ";
  cout << "|\n|<<(1)->Enter an item to be inserted into the tree>>>|"
       << "\n|<<(2)->print the tree.>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(3)->Print the smallest number>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(4)->Print the greatest number>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(5)->read from a file>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(6)->remove an item>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(q)->quit>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << endl;
  for (int i = 0; i<54; i++)
    cout << "-";
}
