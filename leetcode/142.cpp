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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* node=head;
        while(node!=nullptr){
            if(m[node]) return node;
            m[node]=true;
            node=node->next;
        }
        return nullptr;
    }
};

// wow... lets think as mathematical. set variables. generalization!!!
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=nullptr){
            
            fast=fast->next;
            if(fast==nullptr) return nullptr;
            fast=fast->next;
            slow=slow->next;
            
            
            if(fast==slow) break;
        }
        if(fast==nullptr) return fast;
        
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
        
    }
};