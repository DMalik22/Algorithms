//A solution to the reverse-given-linked-list problem using 3 pointers.

/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  Node* nextNode;
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = nullptr;
  nextNode  = currNode->next;
  while(nextNode != nullptr){ 
    currNode->next = prevNode;   
    prevNode = currNode;
    currNode = nextNode;
    nextNode = nextNode->next;
  }
  currNode->next = prevNode;

  return currNode;
}
