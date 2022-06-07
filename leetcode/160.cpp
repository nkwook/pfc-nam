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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;
        
        ListNode* traverse=headA;
        while(traverse){
            traverse=traverse->next;
            lenA++;
        }
        
        traverse=headB;
        while(traverse){
            traverse=traverse->next;
            lenB++;
        }
        
        int lenMin=min(lenA, lenB);
        
        for(int i=0;i<lenA-lenMin;i++){
            headA=headA->next;
        }
        for(int i=0;i<lenB-lenMin;i++){
            headB=headB->next;
        }
        
        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    
    }
};