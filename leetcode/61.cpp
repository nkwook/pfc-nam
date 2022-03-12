/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(head ==nullptr){
        return head;
      }
      ListNode *cur=head;
      int length=1;
      while(cur->next!=nullptr){
        length++;
        cur=cur->next;
      }    

      k=k%length;
      if(k==0){
        return head;
      }

      cur=head;
      for(int i=0;i<length-k-1;i++){
        cur=cur->next;
      }
      ListNode * newEnd=cur;
      ListNode *newHead=cur->next; 
      
      while(cur->next!=nullptr){
        cur=cur->next;
      }
      cur->next=head;
      newEnd->next=nullptr;
      return newHead;
      
    }
};