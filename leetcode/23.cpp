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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=new ListNode();
        ListNode *t=head;
        
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;
//         priority_queue<pair<int, int> > pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]==nullptr) continue;
            pq.push({lists[i]->val, i});
        }
        
        while(!pq.empty()){
            
            int minIndex=pq.top().second;
            ListNode* minNode=lists[minIndex];
            pq.pop();
            
            
            t->next=minNode;
            t=t->next;
            lists[minIndex]=minNode->next;
            if(minNode->next!=nullptr){
                pq.push({minNode->next->val, minIndex});
            }
            
        }
        
        return head->next;
    }
};