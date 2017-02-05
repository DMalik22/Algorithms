/*
 In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:
 
 1 x: Enqueue element  into the end of the queue.
 2: Dequeue the element at the front of the queue.
 3: Print the element at the front of the queue.
 Input Format
 
 The first line contains a single integer, q, denoting the number of queries.
 Each line i of the q subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query type, but only query i is followed by an additional space-separated value, x , denoting the value to be enqueued.
 
 It is guaranteed that a valid answer always exists for each query of type.
 Output Format
 
 For each query, print the value of the element at the front of the queue on a new line.
 
 Sample Input
 
 10
 1 42
 2
 1 14
 3
 1 28
 3
 1 60
 1 78
 2
 2
 
 Sample Output
 
 14
 14
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> stack_newest_on_top, stack_oldest_on_top;
  
  void shiftStacks(){
    if(stack_oldest_on_top.empty()){
      while(!stack_newest_on_top.empty()){
        stack_oldest_on_top.push(stack_newest_on_top.top());
      stack_newest_on_top.pop();
      }
    }
  }
    public:
  
        void enqueue(int x) {
          stack_newest_on_top.push(x);
        }

        void dequeue() {
          shiftStacks();
            stack_oldest_on_top.pop();
        }

        int front() {
          shiftStacks();
          return stack_oldest_on_top.top();
        }
        
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.enqueue(x);
        }
        else if(type == 2) {
            q1.dequeue();
        }
        else cout << q1.front() << endl;
    }
  
    return 0;
}


