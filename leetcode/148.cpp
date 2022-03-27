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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=nullptr;
        return merge(sortList(head), sortList(slow));

    }
    

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode * h=new ListNode(0);
        ListNode * t=h;
        while(a!=nullptr && b!=nullptr){
            if(a->val > b->val){
                t->next=b;
                b=b->next;
            }else{
                t->next=a;
                a=a->next;
            }
            t=t->next;
        }
        while(a!=nullptr){
            t->next=a;
            a=a->next;
            t=t->next;
        }
        while(b!=nullptr){
            t->next=b;
            b=b->next;
            t=t->next;
        }
        
        return h->next;
        
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
class Solution { //quick sort 했다가 멸망. 
public:
    ListNode* sortList(ListNode* head) {
        unordered_map<ListNode*, bool> m;
        return rec(nullptr,  head, m);
        
    }
    
    ListNode* rec(ListNode* preConnect, ListNode* pivot, unordered_map<ListNode*, bool>& m){
        if(pivot==nullptr) return nullptr;
        ListNode* cur=pivot->next;
        ListNode* prev=pivot;
        ListNode* pivPrev=pivot;
        while(cur!=nullptr && m[cur]!=true){
            if(cur->val < pivot->val){
                prev->next=cur->next;
                // ListNode* temp=pivPrev
                cur->next=pivPrev;
                
                pivPrev=cur;
                if(preConnect!=nullptr) preConnect->next=pivPrev;
                
                cur=prev->next;
            }else{
                prev=cur;
                cur=cur->next;                
            }
        }
        m[pivot]=true;
           
        if(pivot->next !=nullptr && !m[pivot->next]) rec(pivot, pivot->next, m);
        if(pivPrev!=pivot) pivPrev=rec(preConnect, pivPrev, m);   
        return pivPrev;
    }
    
};