/*
 If the code input uses brackets correctly, output “Success". Otherwise, output the 1-based index of the first unmatched closing bracket, 
 and if there are no unmatched closing brackets, output the 1-based index of the first unmatched opening bracket.
 */

#include <iostream>
#include <stack>
#include <string>

struct Bracket {
  Bracket(char type, int position):
  type(type),
  position(position)
  {}
  
  bool Matchc(char c) {
    if (type == '[' && c == ']')
      return true;
    if (type == '{' && c == '}')
      return true;
    if (type == '(' && c == ')')
      return true;
    return false;
  }
  
  char type;
  int position;
};

int main() {
  std::string text;
  getline(std::cin, text);
  
  std::stack <Bracket> opening_brackets_stack;
  
  bool isUnmatchedClosingBracketPresent = false;
  
  for (int position = 0; position < text.length(); ++position) {
    char next = text[position];
    
    if (next == '(' || next == '[' || next == '{') {
      opening_brackets_stack.push(Bracket(next, position));
    }
    
    if (next == ')' || next == ']' || next == '}') {
      if (opening_brackets_stack.size() > 0){
        if (opening_brackets_stack.top().Matchc(next)){
          opening_brackets_stack.pop();
        }
        else{
          opening_brackets_stack.push(Bracket(next, position));
          isUnmatchedClosingBracketPresent = true;
          break;
        }
      }
      else{
        opening_brackets_stack.push(Bracket(next, position));
        isUnmatchedClosingBracketPresent = true;
        break;
      }
    }
  }
  
  if (opening_brackets_stack.size() == 0)
    std::cout << "Success" << std::endl;
  else{
    if (isUnmatchedClosingBracketPresent){
      std::cout << opening_brackets_stack.top().position + 1 << std::endl;
      while (opening_brackets_stack.size() != 0) {
        opening_brackets_stack.pop();
      }
    }
    else{
      int to_display = 0;
      while(opening_brackets_stack.size() != 0){
        to_display = opening_brackets_stack.top().position;
        opening_brackets_stack.pop();
      }
      std::cout << to_display + 1 << std::endl;
    }
  }
  return 0;
}
