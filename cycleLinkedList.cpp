//Solved the problem using the runner technique described in CTCI

/*
 Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
 
 A Node is defined as:
 struct Node {
 int data;
 struct Node* next;
 }
 */

bool has_cycle(Node* head) {
  // Complete this function
  // Do not write the main method
  
  if(head == nullptr)
    return 0;
  
  Node* slow;
  Node* fast;
  
  slow = head;
  fast = head;
  
  while(fast != nullptr && fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    
    //if pointers collide then it means that there's a cycle
    if(fast == slow)
      return true;
  }
  
  return false;
}
