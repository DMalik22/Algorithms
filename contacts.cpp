//Used STL to solve a CTCI problem on Hackerrank
/*
 We're going to make our own Contacts application! The application must perform two types of operations:
  1. add name, where name is a string denoting a contact name. This must store name as a new contact in the application.
  2. find partial, where partial is a string denoting a partial name to search the application for. It must count the number of contacts starting with partial and print the count on a new line.
 Given n sequential add and find operations, perform each operation in order.

 Input Format
 The first line contains a single integer, n, denoting the number of operations to perform.
 Each line i of the n subsequent lines contains an operation in one of the two forms defined above.
 
 Output Format
 For each find partial operation, print the number of contact names starting with partial on a new line.
 
 Sample Input
 4
 add hack
 add hackerrank
 find hac
 find hak
 Sample Output
 
 Sample Output
 2
 0
 */

#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(){
  int n;
  cin >> n;
  set<string> contactsApp;
  for(int a0 = 0; a0 < n; a0++){
    string op;
    string contact;
    cin >> op >> contact;
    
    if(op == "add")
      contactsApp.insert(contact);
    
    if(op == "find"){
      int count = 0;
      set<string>::iterator it = contactsApp.lower_bound(contact);
      while(it != contactsApp.end() && (it->find(contact) == 0)){
        count++;
        it++;
      }
      cout << count << endl;
    }
    
  }
  return EXIT_SUCCESS;
}
