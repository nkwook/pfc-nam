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

// can do with 2pointer(window slide)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // size ?
        ListNode* l=head;
        int cnt=0;
        while(l !=nullptr){
            cnt++;
            l=l->next;
        }
        
        int idx=cnt-n;

        l=head;
        if(idx==0){
            return head->next;
        }
        for(int i=0;i<idx;i++){
            if(i==idx-1){
                if(n==0){
                    l->next=nullptr;
                    break;
                }
                ListNode * t=l;
                t=t->next;
                t=t->next;
                
                l->next=t;
                break;
            }
            l=l->next;
        }
        return head;
        
        
        
    }
};