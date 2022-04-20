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
    ListNode* reverseList(ListNode* head) {
        
        if(head== nullptr || head->next==nullptr){
            return head;            
        }
        
        ListNode* rNode=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return rNode;   
    }
    

};

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
    ListNode* reverseList(ListNode* head) {
        
        if(head== nullptr || head->next==nullptr){
            return head;            
        }
        
        ListNode* temp=head->next;
        ListNode* tempNext=head->next;

        head->next=nullptr;
        while(tempNext!=nullptr){
            tempNext=temp->next;
            temp->next=head;
            head=temp;
            temp=tempNext;
        }
        return head;
    }
};