/** 재귀로도 짜봅시다
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur=head;
        ListNode* prev=nullptr;
        ListNode* temp=nullptr;
        if(head==nullptr) return head;
        if(head->next!=nullptr){
            head=head->next;
        }
        while(cur!=nullptr){
            if(cur->next==nullptr) break;
            if(prev!=nullptr){
                prev->next=cur->next;
            }
            prev=cur;
            temp=cur->next->next;
            cur->next->next=cur;
            cur->next=temp;
            
            cur=cur->next;
            // cur=cur->next;
        }
            
            
        return head;
    }
};