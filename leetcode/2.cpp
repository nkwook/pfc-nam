#include <iostream>
using namespace std;


//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r=new ListNode();
        ListNode *rT=r;

        ListNode *t1=l1;
        ListNode *t2=l2;
        int x=0;
        int temp=0;
        int rVal=0;
        bool cont=t1 !=nullptr || t2!=nullptr || x!=0;
        while(cont){
            
            if(t1 !=nullptr && t2 !=nullptr){
                temp=t1->val+t2->val+x;
            }else if(t1!=nullptr){
                temp=t1->val+x;
            }else if(t2!=nullptr){
                temp=t2->val+x;
            }else{
                temp=x;
            }

            if(temp>9){
                x=temp/10;
                rVal=temp%10;
            }else{
                x=0;
                rVal=temp;
            }
            rT->val=rVal;
            if(t1!=nullptr)   t1=t1->next;
            if(t2!=nullptr)   t2=t2->next;   
                
            cont=t1 !=nullptr || t2!=nullptr || x!=0;
            if(cont){
                rT->next=new ListNode();
                rT=rT->next;
                
            }
        }

        return r;


    }
};


int main(){
    Solution s;

    // ListNode *l1=new ListNode(1, new ListNode(2, new ListNode(3)));
    // ListNode *l2=new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l1=new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode *l2=new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode * r=s.addTwoNumbers(l1, l2);
    while(r!=nullptr){
        cout << r->val << ' ';
        r=r->next;
    }
    // // cout << s.mergeTwoLists(l1, l2);


}