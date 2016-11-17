/*Author: Matthew Austin
 *File: main.cpp
 *Date:11/15/2016
 *Purpose: This is the main driver for my program that allows manipulation of 
 *the tree
 */
#include "binary_search_tree.h"
using namespace std;

void print_welcome();

int main(){
  string file;
  binary_search_tree first_tree;
  string key;
  char answer;
  print_welcome();//welcome screen
  cin >> answer;//priming read
  while(answer != 'q'){
    if (answer == '1'){//inserts a given key and data
      cout << "Please enter the key you would like to insert: ";
      cin >> key;
      if (first_tree.find(key) != -1){
	
	first_tree[key]++;
	cout << "The count for [" << key << "] is " << first_tree[key] << endl;
      }
      else {
	first_tree.set(key);
	cout << "The count for [" << key << "] is " << first_tree[key] << endl;
      }
    }
    else if(answer == '2')//prints the tree lexicographically
      first_tree.print();
    else if(answer == '3')//prints the first key lexicographically
      first_tree.min();
    else if(answer == '4')//prints the last key lexicographically
      first_tree.max();
    else if(answer == '5'){//reads from a file and inserts into the tree
      cout << "Please enter a file to read from: ";
      cin >> file;
      first_tree.read_from_file(file);
    }
    else if (answer == '6'){//removes a specific Node basedon the key
      cout << "Please enter the key of the item you wish to delete: ";
      cin >> key;
      first_tree.remove(key);
    }
    else if (answer == '7'){//saves the tree to a given file
      cout << "Please enter the file you wish to save the tree in: ";
      cin >> file;
      first_tree.save_file(file);
    }
    else if (answer == '8'){//find the data for a given key
      cout << "Please enter the key of the data you wish to know: ";
      cin >> key;
      cout << "The count for " << key << " is " << first_tree[key] << endl;
    }
    else if (answer == '9')//erase the entire tree
      first_tree.erase_tree();
    print_welcome();//welcome screen
    cin >> answer;//last read
  }
  return 0;
}
void print_welcome(){
  for (int i = 0; i<54; i++)
    cout << "-";//top of the box
  //Welcome screen
  cout << "\n|<<<<<WELCOME TO THE FANTASTIC TREE MANIPULATOR>>>>>>|"
       << "\n|<<<<<Please enter one of the following options>>>>>>|\n|";
  
  for(int i = 0; i<52; i++)//empty line
    cout << " ";
  //options
  cout << "|\n|<<(1)->Enter an item to be inserted into the tree>>>|"
       << "\n|<<(2)->Print the tree>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(3)->Print the first word alphabetically>>>>>>>>>>|"
       << "\n|<<(4)->Print the last word alphabetically>>>>>>>>>>>|"
       << "\n|<<(5)->Read from a file>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(6)->Remove an item>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(7)->Save tree to a file>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(8)->Get the count of a given key>>>>>>>>>>>>>>>>>|"
       << "\n|<<(9)->Erase the entire tree>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(q)->Quit>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << endl;
  for (int i = 0; i<54; i++)
    cout << "-";//bottom of the box
  cout << "\n?";
}
