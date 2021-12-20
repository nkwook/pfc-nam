#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * transverse=new ListNode();
        ListNode * result=transverse;
        

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val>list2->val){
                transverse->next=list2;
                list2=list2->next;
                transverse=transverse->next;     
            }else {
                transverse->next=list1;
                list1=list1->next;
                transverse=transverse->next;
            }
        }
        while(list1!=nullptr){
            transverse->next=list1;
            list1=list1->next;
            transverse=transverse->next;
        }
        while(list2!=nullptr){
            transverse->next=list2;
            list2=list2->next;
            transverse=transverse->next;
        }

        return result->next;
    }
};


int main(){
    Solution s;

    // ListNode *l1=new ListNode(1, new ListNode(2, new ListNode(3)));
    // ListNode *l2=new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l1=new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode *l2=new ListNode(1, new ListNode(2, new ListNode(4)));

    ListNode * r=s.mergeTwoLists(l1, l2);
    while(r!=nullptr){
        cout << r->val << ' ';
        r=r->next;
    }
    // cout << s.mergeTwoLists(l1, l2);


}