
/*
 Solved a simple Hackkerank/CTCI problem
 
 Input Format
 
 The first line contains a single integer, enoting the number of strings.
 Each line  of the  subsequent lines consists of a single string denoting a sequence of brackets.
 
 Constraints
 Each character in the sequence will be a bracket (i.e., {, }, (, ), [, and ]).
 Output Format
 
 For each string, print whether or not the string of brackets is balanced on a new line. If the brackets are balanced, print YES; otherwise, print NO.
 
 Sample Input
 
 3
 {[()]}
 {[(])}
 {{[[(())]]}}
 Sample Output
 
 YES
 NO
 YES

 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
  char c;
  stack <char> brackets;
  
  for(auto i: expression){
    if ((i == '(') || (i == '{') || (i == '['))
      brackets.push(i);
    else{
      if(brackets.size() == 0)
        return false;
      if(i == ')'){
        if(brackets.top() == '(')
          brackets.pop();
        else
          return false;
      }
      if(i == ']'){
        if(brackets.top() == '[')
          brackets.pop();
        else
          return false;
      }
      if(i == '}'){
        if(brackets.top() == '{')
          brackets.pop();
        else
          return false;
      }
    }
  }
  
  if (brackets.size() != 0)
    return false;
  
  return true;
}

int main(){
  int t;
  cin >> t;
  for(int a0 = 0; a0 < t; a0++){
    string expression;
    cin >> expression;
    bool answer = is_balanced(expression);
    if(answer)
      cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}

