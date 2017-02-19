/*
 Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void insert(ListNode* head, unsigned long d){
    ListNode* dummy = head;
    while(dummy->next != nullptr)
      dummy = dummy->next;
    ListNode newNode = ListNode(d);
    dummy->next = &newNode;
  }
  
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr)
      return nullptr;
    
    unsigned long a = 0;
    unsigned long b = 0;
    unsigned long c = 0;
    
    if(l1 != nullptr){
      a = l1->val;
      while(l1->next != nullptr){
        l1 = l1->next;
        a = a*10 + l1->val;
      }
    }
    
    if(l2 != nullptr){
      b = l2->val;
      while(l2->next != nullptr){
        l2 = l2->next;
        b = b*10 + l2->val;
      }
    }
    
    c = a + b;
    
    ListNode* head = new ListNode(c % 10);
    c /= 10;
    
    if(c){
      while(c){
        ListNode* dummy = new ListNode(c % 10);
        dummy->next = head;
        head = dummy;
        c /= 10;
      }
    }
    return head;
  }
};
